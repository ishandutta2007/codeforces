#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);


void precalc() {
}

bool isvic(int year) {
  return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

int s1, m1, h1, day, date, month;

int read() {
  if (scanf("%d%d%d%d%d%d", &s1, &m1, &h1, &day, &date, &month) < 6) {
    return 0;
  }
  --day;
  day = max(day, -1);
  --date;
  date = max(date, -1);
  --month;
  month = max(month, -1);
  return 1;
}

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void addDay(int &year, int &month, int &day, int &curday, long long &x0) {
  x0 -= x0 % (60 * 60 * 24);
  if (++curday == 7) {
    curday = 0;
  }
  ++day;
  if (day == days[month]) {
    ++month;
    day = 0;
    if (month == 12) {
      if (isvic(year)) {
        --days[1];
      }
      ++year;
      if (isvic(year)) {
        ++days[1];
      }
      month = 0;
    }
  }
}


void solve() {
  int whole = 0;
  for (int i = 0; i < 400; ++i) {
    int year = 1970 + i;
    whole += 365 + isvic(year);
  }

  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    long long x;
    scanf("%lld", &x);
    ++x;

    int curday = (x / (60 * 60 * 24) + 3) % 7;
    long long x0 = x;

    x %= ((long long) (60 * 60 * 24) * whole);
    int year = 1970;
    while (1) {
      int cur = (365 + isvic(year)) * (60 * 60 * 24);
      if (x < cur) {
        break;
      }
      x -= cur;
      ++year;
    }
    int d = x / (60 * 60 * 24);
    int m = 0;

    if (isvic(year)) {
      ++days[1];
    }

    while (d >= days[m]) {
      d -= days[m];
      ++m;
    }
    assert(m < 12);
    assert(d < 32);
    //eprintf("%d %d %d\n", year, m, d);

    int addday = 0;

    while (1) {
      while (1) {
        //eprintf("%d %d %d %d\n", year, m, d, curday);
        if (month == -1 || month == m) {
          bool ok1 = (date == -1 || date == d);
          bool ok2 = (day == -1 || day == curday);
          if ((ok1 && ok2) || (date != -1 && day != -1 && (ok1 || ok2))) {
            break;
          }
        }
        addDay(year, m, d, curday, x0);
        ++addday;
      }

      //eprintf("CHECK!\n");
      int half = x0 % (60 * 60 * 24);
      auto x00 = x0;
      while (half < 60 * 60 * 24) {
        bool ok = 1;
        if (s1 != -1) {
          if (half % 60 != s1) {
            ok = 0;
          }
        }
        if (m1 != -1) {
          if (half / 60 % 60 != m1) {
            ok = 0;
          }
        }
        if (h1 != -1) {
          if (half / (60 * 60) != h1) {
            ok = 0;
          }
        }
        if (ok) {
          break;
        }
        ++x0;
        ++half;
      }
      if (half != 60 * 60 * 24) {
        break;
      }
      x0 = x00;
      half = 0;
      addDay(year, m, d, curday, x0);
      ++addday;
    }
    x0 += addday * 60 * 60 * 24;
    printf("%lld\n", x0);

    if (isvic(year)) {
      --days[1];
    }
  }
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".out", "w", stdout));
  assert(freopen(TASK ".in", "r", stdin));
#endif

  while (read()) {
    solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
    //break;
  }

  return 0;
}