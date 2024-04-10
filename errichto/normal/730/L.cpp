#include <bits/stdc++.h>

#define debug(a)

using namespace std;

using ll = long long int;

constexpr int mod = 1000 * 1000 * 1000 + 7;

ll Add(ll a, ll b) { return (a + b) % mod; }
ll Mul(ll a, ll b) { return (a * b) % mod; }

ll pot10[1000 * 1000 + 5];

char buf[1000 * 1000 + 5];
int position = 1;

char Read() {
  return buf[position++];
}

int Position() {
  return position;
}

void PutBack() {
  position--;
}

struct Token;

Token* token[1000 * 1000 + 5];

struct Liczba {
  ll value;
  int len;

  Liczba operator/(const Liczba& l) const {
    Liczba nowa;
    nowa.value = Add(Mul(value, pot10[l.len]), l.value);
    nowa.len = len + l.len;
    return nowa;
  }
};

struct Value {
  ll lewo, sum, prawo;
  ll cale;

  static Value MakeCale(ll c) {
    return Value{0ll, 0ll, 0ll, c};
  }

  static Value MakeRozbite(ll l, ll s, ll p) {
    return Value{l, s, p, -2ll};
  }

  ll Get() const {
    if (Cale()) return cale;
    else return Add(lewo, Add(sum, prawo));
  }

  bool Cale() const {
    return cale != -2ll;
  }

  Value operator+(const Value& v) const {
    if (Cale() and v.Cale()) {
      return MakeRozbite(Get(), 0ll, v.Get());
    } else if (Cale()) {
      return MakeRozbite(Get(), v.lewo + v.sum, v.prawo);
    } else if (v.Cale()) {
      return MakeRozbite(lewo, sum + prawo, v.Get());
    } else {
      return MakeRozbite(lewo, sum + prawo + v.lewo + v.sum, v.prawo);
    }
  }

  Value operator*(const Value& v) const {
    if (Cale() and v.Cale()) {
      return MakeCale(Mul(Get(), v.Get()));
    } else if (Cale()) {
      return MakeRozbite(Mul(Get(), v.lewo), v.sum, v.prawo);
    } else if (v.Cale()) {
      return MakeRozbite(lewo, sum, Mul(prawo, v.Get()));
    } else {
      return MakeRozbite(lewo, sum + Mul(prawo, v.lewo) + v.sum, v.prawo);
    }
  }
};

struct Token {
  vector<pair<char, Token>> tokens;
  int a, b;
  ll val = -1ll;
  int n2;
  vector<Value> drz;
  vector<Liczba> drz2;
  Token* ojciec = nullptr;

  bool JestLiczba() const {
    return tokens.empty();
  }

  Liczba LiczLiczba_(int w, int a, int b, int p, int k) {
    debug( printf("LiczLiczba_(%d, %d, %d, %d, %d)\n", w, a, b, p, k); )
    if (b < p or k < a) return Liczba{0, 0};
    if (a <= p and k <= b) {
      return drz2[w];
    }
    return LiczLiczba_(w * 2, a, b, p, (p + k) / 2) / LiczLiczba_(w * 2 + 1, a, b, (p + k + 1) / 2, k);
  }

  ll LiczLiczba(int p, int k) {
    assert(p <= k);
    assert(a <= p and k <= b);
    debug( printf("LiczLiczba(a/b = [%d, %d], p/k = [%d, %d])\n", a, b, p, k); )
    debug(
      for (int i = p; i <= k; i++) {
        printf(" (%lld, %d)", drz2[i - a + n2].value, drz2[i - a + n2].len);
      }
      printf("\n");
    )
    return LiczLiczba_(1, p - a, k - a, 0, n2 - 1).value;
  }

  void CountPositions(Token* ojc) {
    if (JestLiczba()) {
      for (int i = a; i <= b; i++) {
        token[i] = this;
      }
    } else {
      token[a] = this;
      token[b] = this;
    }
    ojciec = ojc;
    for (auto& t : tokens) {
      t.second.CountPositions(this);
    }
  }

  void Wypisz() {
    if (tokens.empty()) {
      printf("{%p}Liczba(%lld [%d:%d])", this, val, a, b);
    } else {
      printf("{%p}Ciag([%d:%d], val = %lld,", this, a, b, Wartosc());
      for (auto& t : tokens) {
        printf(" %c ", t.first);
        t.second.Wypisz();
      }
      printf(")");
    }
  }

  int ZnajdzPocz(int pos) {
    int a = 0, b = (int) tokens.size() - 1, c;
    while (a <= b) {
      c = (a + b) / 2;
      const Token& t = tokens[c].second;
      if (t.JestLiczba() and t.a <= pos and pos <= t.b) {
        return c;
      } else if (t.a == pos) {
        return c;
      } else if (pos < t.a) {
        b = c - 1;
      } else {
        a = c + 1;
      }
    }
    return -1;
  }

  int ZnajdzKon(int pos) {
    int a = 0, b = (int) tokens.size() - 1, c;
    while (a <= b) {
      c = (a + b) / 2;
      const Token& t = tokens[c].second;
      if (t.JestLiczba() and t.a <= pos and pos <= t.b) {
        return c;
      } else if (t.b == pos) {
        return c;
      } else if (pos < t.b) {
        b = c - 1;
      } else {
        a = c + 1;
      }
    }
    return -1;
  }

  Value Wylicz_(int pos, int a, int b) {
    Token& t = tokens[pos].second;
    if (t.JestLiczba()) {
      return Value::MakeCale(t.LiczLiczba(max(a, t.a), min(b, t.b)));
    } else {
      assert(a <= t.a and t.b <= b);
      return Value::MakeCale(t.Wartosc());
    }
  }

  Value Wylicz(int pos, int a, int b) {
    const Value& val = Wylicz_(pos, a, b);
    debug( printf("Wylicz(%d, %d, %d) = {%lld, %lld, %lld | %lld}\n", pos, a, b, val.lewo, val.sum, val.prawo, val.cale); )
    return val;
  }

  Value Zapytanie(int a, int b) {
    debug( printf("{%p}Zapytanie(%d, %d)\n", this, a, b); )
    debug( Wypisz(); printf("\n"); )
    assert(!tokens.empty());
    const int pocz = ZnajdzPocz(a);
    const int kon = ZnajdzKon(b);
    debug( printf("pocz = %d, kon = %d\n", pocz, kon); )
    if (pocz < 0 or kon < 0) return Value::MakeCale(-1);
    if (pocz > kon) return Value::MakeCale(-1);
    if (pocz == kon) {
      if (tokens[pocz].second.JestLiczba()) {
        return Value::MakeCale(tokens[pocz].second.LiczLiczba(a, b));
      } else {
        return Value::MakeCale(tokens[pocz].second.Wartosc());
      }
    } else if (pocz + 1 == kon) {
      if (tokens[kon].first == '+') {
        return Wylicz(pocz, a, b) + Wylicz(kon, a, b);
      } else {
        return Wylicz(pocz, a, b) * Wylicz(kon, a, b);
      }
    }
    Value lewo = (tokens[pocz + 1].first == '+') ? (Wylicz(pocz, a, b) + Licz(pocz + 1, kon - 1)) : (Wylicz(pocz, a, b) * Licz(pocz + 1, kon - 1));
    if (tokens[kon].first == '+') {
      return lewo + Wylicz(kon, a, b);
    } else {
      return lewo * Wylicz(kon, a, b);
    }
  }

  ll Wartosc() {
    if (val != -1ll) {
      return val;
    }
    Build();
    return val = Licz(0, (int) tokens.size() - 1).Get();
  }

  Value Licz_(int w, int a, int b, int p, int k) {
    debug( printf("Licz_(%d, %d, %d, %d, %d)\n", w, a, b, p, k); )
    if (b < p or k < a) assert(false);
    if (a <= p and k <= b) {
      return drz[w];
    }
    const int s = (p + k + 1) / 2;
    if (a < s and s <= b) {
      if (tokens[s].first == '+') {
        return Licz_(w * 2, a, b, p, s - 1) + Licz_(w * 2 + 1, a, b, s, k);
      } else {
        return Licz_(w * 2, a, b, p, s - 1) * Licz_(w * 2 + 1, a, b, s, k);
      }
    } else if (a < s) {
      return Licz_(w * 2, a, b, p, s - 1);
    } else {
      return Licz_(w * 2 + 1, a, b, s, k);
    }
  }

  Value Licz(int a, int b) {
    Build();
    return Licz_(1, a, b, 0, n2 - 1);
  }

  void Przelicz(int w, int p, int k) {
    if (p == k) {
      if (k < (int) tokens.size()) {
        drz[w] = Value::MakeCale(tokens[k].second.Wartosc());
      } else {
        drz[w] = Value::MakeCale(0);
      }
      return;
    }
    const int s = (p + k + 1) / 2;
    Przelicz(w * 2, p, s - 1);
    Przelicz(w * 2 + 1, s, k);
    char c = '?';
    if (s < (int) tokens.size()) {
      c = tokens[s].first;
    } else {
      c = '+';
    }
    if (c == '+') {
      drz[w] = drz[w * 2] + drz[w * 2 + 1];
    } else {
      drz[w] = drz[w * 2] * drz[w * 2 + 1];
    }
  }

  void Build() {
    if (!drz.empty()) return;
    n2 = 1;
    while (n2 < (int) tokens.size()) {
      n2 *= 2;
    }
    drz.resize(n2 * 2);
    Przelicz(1, 0, n2 - 1);
  }

  void ReadInt() {
    vector<int> cyfry;
    a = Position();
    val = 0ll;
    while (true) {
      const char c = Read();
      if ('0' <= c and c <= '9') {
        cyfry.push_back(c - '0');
        val = Add(Mul(val, 10), c - '0');
      } else {
        PutBack();
        break;
      }
    }
    b = Position() - 1;
    n2 = 1;
    while (n2 < (int) cyfry.size()) {
      n2 *= 2;
    }
    drz2.resize(n2 * 2);
    for (int i = 0; i < (int) cyfry.size(); i++) {
      drz2[n2 + i] = Liczba{cyfry[i], 1};
    }
    for (int i = (int) cyfry.size(); i < n2; i++) {
      drz2[n2 + i] = Liczba{0, 0};
    }
    for (int i = n2 - 1; i >= 1; i--) {
      drz2[i] = drz2[i * 2] / drz2[i * 2 + 1];
    }
  }

  void Parse() {
    a = Position() - 1;
    //token[a] = this;
    char last = '?';
    while (true) {
      const char c = Read();
      switch (c) {
        case ')':
          b = position - 1;
          //token[b] = this;
          return;

        case '+':
        case '*':
          last = c;
          break;

        case '(':
          tokens.emplace_back();
          tokens.back().first = last;
          tokens.back().second.Parse();
          break;

        default:
          assert('0' <= c and c <= '9');
          tokens.emplace_back();
          tokens.back().first = last;
          PutBack();
          tokens.back().second.ReadInt();
      }
    }
  }
};

ll zapytanie(int a, int b) {
  debug( printf("zapytanie(%d, %d)\n", a, b); )
  if (token[a] == nullptr or token[b] == nullptr or token[a]->ojciec == nullptr or token[a]->ojciec != token[b]->ojciec) {
    return -1;
  }
  return token[a]->ojciec->Zapytanie(a, b).Get();
}

int main() {
  pot10[0] = 1ll;
  for (int i = 1; i < 1000 * 1000; i++) {
    pot10[i] = Mul(pot10[i - 1], 10);
  }
  scanf("%[^\n]\n", buf + 1);
  buf[0] = '(';
  buf[strlen(buf) + 1] = '\0';
  buf[strlen(buf)] = ')';
  Token token;
  token.Parse();
  token.CountPositions(nullptr);
  debug( token.Wypisz(); printf("\n"); )
  int m;
  scanf("%d", &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", zapytanie(a, b));
  }
  return 0;
}