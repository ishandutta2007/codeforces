/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Egor Kulikov
 */




#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const double PI = atan(1) * 4;

template<typename T>
T minim(T &was, T cand) {
    return was = min(was, cand);
}

template<typename T>
T maxim(T &was, T cand) {
    return was = max(was, cand);
}


template<typename D>
D dPower(D base, ll exponent) {
    if (exponent < 0) {
        return dPower(1 / base, -exponent);
    }
    if (exponent == 0) {
        return 1;
    }
    if ((exponent & 1) == 1) {
        return dPower(base, exponent - 1) * base;
    } else {
        D res = dPower(base, exponent >> 1);
        return res * res;
    }
}


template<typename T>
class arr {
    T *b;
    T *e;
    int n;
public:
    arr() : b(nullptr), e(nullptr), n(0) {}

    arr(int n) : n(n) {
        b = new T[n];
        e = b + n;
    }

    arr(int n, T init) : n(n) {
        b = new T[n];
        e = b + n;
        fill(b, e, init);
    }

    size_t size() const {
        return n;
    }

    T *begin() {
        return b;
    }

    T *end() {
        return e;
    }

    arr<T> clone() {
        arr<T> res(n);
        copy(b, e, res.begin());
        return res;
    }

    T &operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    const T &operator[](int at) const {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }
};

typedef arr<int> arri;

void decreaseByOne() {}

template<typename T, class...Vs>
void decreaseByOne(arr<T> &array, Vs &...vs) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        array[i]--;
    }
    decreaseByOne(vs...);
}

template<typename T, typename U>
void decreaseByOne(arr<pair<T, U> > &v) {
    for (auto &p : v) {
        p.first--;
        p.second--;
    }
}


inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
private:
    istream &in;
    bool exhausted = false;

    inline int get() {
        if (exhausted) {
            throw "Input exhausted";
        }
        int c = in.get();
        if (c == EOF) {
            exhausted = true;
        }
        return c;
    }

    template<typename T>
    inline T readInteger() {
        skipWhitespace();
        int c = get();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        T res = 0;
        do {
            if (!isdigit(c)) {
                throw "Number format error";
            }
            res *= 10;
            res += c - '0';
            c = get();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    void initArrays(int n) {}

    template<typename T, class...Vs>
    void initArrays(int n, arr<T> &array, Vs &...vs) {
        array = arr<T>(n);
        initArrays(n, vs...);
    }

    void readImpl(int i) {}

    template<typename T, class...Vs>
    void readImpl(int i, arr<T> &arr, Vs &...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

public:
    Input(istream &in) : in(in) {};

    inline void skipWhitespace() {
        int c;
        while (isWhitespace(c = in.peek()) && c != EOF) {
            in.get();
        }
        if (c == EOF) {
            exhausted = true;
        }
    }

    inline int readInt() {
        return readInteger<int>();
    }

    ll readLong() {
        return readInteger<ll>();
    }

    string readString() {
        skipWhitespace();
        int c = get();
        if (c == EOF) {
            throw "Input exhausted";
        }
        vector<char> res;
        do {
            res.push_back(c);
        } while (!isWhitespace(c = get()));
        return string(all(res));
    }

    arri readIntArray(int size) {
        return readArray<int>(size);
    }

    template<typename T>
    T readType() {
        throw "Operation not supported";
    }

    template<typename U, typename V>
    pair<U, V> readType() {
        U first = readType<U>();
        V second = readType<V>();
        return make_pair(first, second);
    }

    template<typename T>
    arr<T> readArray(int n) {
        arr<T> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = readType<T>();
        }
        return res;
    }


    template<class...Vs>
    void readArrays(int n, Vs &...vs) {
        initArrays(n, vs...);
        for (int i = 0; i < n; i++) {
            readImpl(i, vs...);
        }
    }

    template<typename U, typename V>
    arr<pair<U, V> > readArray(int n) {
        arr<pair<U, V> > res(n);
        for (int i = 0; i < n; i++) {
            res[i] = readType<U, V>();
        }
        return res;
    }

    template<typename T>
    vector<vector<T> > readTable(int rows, int cols) {
        vector<vector<T> > result;
        result.reserve(rows);
        for (int i = 0; i < rows; ++i) {
            result.push_back(readArray<T>(cols));
        }
        return result;
    }

    string readLine() {
//        skipWhitespace();
        int c = get();
        if (c == EOF) {
            throw "Input exhausted";
        }
        int length = 0;
        vector<char> res;
        do {
            res.push_back(c);
            if (!isWhitespace(c)) {
                length = res.size();
            }
            c = get();
        } while (c != '\n' && c != '\r' && c != EOF);
        return string(res.begin(), res.begin() + length);
    }

    double readDouble() {
        skipWhitespace();
        int c = get();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        double res = 0;
        do {
            if (tolower(c) == 'e') {
                return sgn * res * dPower(10, readInt());
            }
            if (!isdigit(c)) {
                throw "Number format error";
            }
            res *= 10;
            res += c - '0';
            c = get();
        } while (!isWhitespace(c) && c != '.');
        if (c == '.') {
            double add = 0;
            int length = 0;
            c = get();
            do {
                if (tolower(c) == 'e') {
                    return sgn * (res + add * dPower(10, -length)) * dPower(10, readInt());
                }
                if (!isdigit(c)) {
                    throw "Number format error";
                }
                add *= 10;
                add += c - '0';
                length++;
                c = get();
            } while (!isWhitespace(c));
            res += add * dPower(10, -length);
        }
        return res * sgn;
    }

    char readChar() {
        skipWhitespace();
        int c = get();
        if (c == EOF) {
            throw "Input exhausted";
        }
        return c;
    }

    bool isExhausted() { return exhausted; }
};

template<>
double Input::readType() {
    return readDouble();
}

template<>
int Input::readType() {
    return readInt();
}

template<>
ll Input::readType() {
    return readLong();
}

template<>
char Input::readType() {
    return readChar();
}

template<>
string Input::readType() {
    return readString();
}


class Output {
private:
    ostream &out;

    template<typename T>
    void printSingle(const T &value) {
        out << value;
    }

    template<typename T>
    void printSingle(const vector<T> &array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const arr<T> &array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }

    template<typename T, typename U>
    void printSingle(const pair<T, U> &value) {
        out << value.first << ' ' << value.second;
    }

public:
    Output(ostream &out) : out(out) {
        out << fixed << setprecision(12);
    }

    void print() {}

    template<typename T, typename...Targs>
    void print(const T &first, const Targs... args) {
        printSingle(first);
        if (sizeof...(args) != 0) {
            out << ' ';
            print(args...);
        }
    }

    template<typename...Targs>
    void printLine(const Targs... args) {
        print(args...);
        out << '\n';
    }

    void flush() {
        out.flush();
    }
};


class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int v) : v(v) {}

    operator int &() { return v; }

    int operator*() { return v; }
};

class Range : pii {
public:
    Range(int begin, int end) : pii(begin, max(begin, end)) {}

    Range(int n) : pii(0, max(0, n)) {}

    NumberIterator begin() {
        return first;
    }

    NumberIterator end() {
        return second;
    }
};


const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int MODF = 998244353;

int mod = MOD7;

template<typename T>
T gcd(T a, T b, T &x, T &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int d = gcd(b % a, a, y, x);
    x -= (b / a) * y;
    return d;
}

class modint {
public:
    int n;

    modint() : n(0) {}

    modint(ll n) {
        if (n >= 0 && n < mod) {
            this->n = n;
            return;
        }
        n %= mod;
        if (n < 0) {
            n += mod;
        }
        this->n = n;
    }

    modint &operator+=(const modint &other) {
        n += other.n;
        if (n >= mod) {
            n -= mod;
        }
        return *this;
    }

    modint &operator-=(const modint &other) {
        n -= other.n;
        if (n < 0) {
            n += mod;
        }
        return *this;
    }

    modint &operator*=(const modint &other) {
        n = ll(n) * other.n % mod;
        return *this;
    }

    modint operator-() {
        if (n == 0) {
            return 0;
        }
        return modint(mod - n);
    }

    modint inverse() {
        ll x, y;
        gcd(ll(n), ll(mod), x, y);
        return x;
    }
};

modint operator+(const modint &a, const modint &b) {
    return modint(a) += b;
}

modint operator-(const modint &a, const modint &b) {
    return modint(a) -= b;
}

modint operator*(const modint &a, const modint &b) {
    return modint(a) *= b;
}

ostream &operator<<(ostream &out, const modint &val) {
    return out << val.n;
}

bool operator==(const modint &a, const modint &b) {
    return a.n == b.n;
}

bool operator!=(const modint &a, const modint &b) {
    return a.n != b.n;
}


template<typename W, typename C>
class WeightedFlowEdge {
private:
    WeightedFlowEdge<W, C> *reverseEdge;

public:
    const int from;
    const int to;
    W weight;
    C capacity;
    int id;

    WeightedFlowEdge(int from, int to, W weight, C capacity) : from(from), to(to), weight(weight), capacity(capacity) {
        reverseEdge = new WeightedFlowEdge(this);
    }

    WeightedFlowEdge<W, C> *transposed() { return nullptr; }

    WeightedFlowEdge<W, C> *reverse() { return reverseEdge; }

    void push(C flow) {
        capacity -= flow;
        reverseEdge->capacity += flow;
    }

    C flow() const {
        return reverseEdge->capacity;
    }

private:
    WeightedFlowEdge(WeightedFlowEdge<W, C> *reverse) : from(reverse->to), to(reverse->from), weight(-reverse->weight),
                                                        capacity(0) {
        reverseEdge = reverse;
    }
};

template<typename C>
class FlowEdge {
private:
    FlowEdge<C> *reverseEdge;

public:
    const int from;
    const int to;
    C capacity;
    int id;

    FlowEdge(int from, int to, C capacity) : from(from), to(to), capacity(capacity) {
        reverseEdge = new FlowEdge(this);
    }

    FlowEdge<C> *transposed() { return nullptr; }

    FlowEdge<C> *reverse() { return reverseEdge; }

    void push(C flow) {
        capacity -= flow;
        reverseEdge->capacity += flow;
    }

    C flow() const {
        return reverseEdge->capacity;
    }

private:
    FlowEdge(FlowEdge<C> *reverse) : from(reverse->to), to(reverse->from), capacity(0) {
        reverseEdge = reverse;
    }
};

template<typename W>
class WeightedEdge {
public:
    const int from;
    const int to;
    W weight;
    int id;

    WeightedEdge(int from, int to, W weight) : from(from), to(to), weight(weight) {
    }

    WeightedEdge<W> *transposed() { return nullptr; }

    WeightedEdge<W> *reverse() { return nullptr; }
};

template<typename W>
class BidirectionalWeightedEdge {
private:
    BidirectionalWeightedEdge<W> *transposedEdge;

public:
    const int from;
    const int to;
    W weight;
    int id;

    BidirectionalWeightedEdge(int from, int to, W weight) : from(from), to(to), weight(weight) {
        transposedEdge = new BidirectionalWeightedEdge(this);
    }

    BidirectionalWeightedEdge<W> *transposed() { return transposedEdge; }

    BidirectionalWeightedEdge<W> *reverse() { return nullptr; }

private:
    BidirectionalWeightedEdge(BidirectionalWeightedEdge<W> *transposed) : from(transposed->to), to(transposed->from),
                                                                          weight(transposed->weight) {
        transposedEdge = transposed;
    }
};

class SimpleEdge {
public:
    const int from;
    const int to;
    int id;

    SimpleEdge(int from, int to) : from(from), to(to) {
    }

    SimpleEdge *transposed() { return nullptr; }

    SimpleEdge *reverse() { return nullptr; }
};

class BidirectionalEdge {
private:
    BidirectionalEdge *transposedEdge;

public:
    const int from;
    const int to;
    int id;

    BidirectionalEdge(int from, int to) : from(from), to(to) {
        transposedEdge = new BidirectionalEdge(this);
    }

    BidirectionalEdge *transposed() { return transposedEdge; }

    BidirectionalEdge *reverse() { return nullptr; }

private:
    BidirectionalEdge(BidirectionalEdge *transposed) : from(transposed->to), to(transposed->from) {
        transposedEdge = transposed;
    }
};

template<class Edge>
class Graph {
public:
    int vertexCount;
    int edgeCount = 0;
    vector<vector<Edge *> > edges;

    Graph(int vertexCount) : vertexCount(vertexCount) {
        edges.resize(vertexCount);
    }

    void addEdge(Edge *edge) {
        edge->id = edgeCount;
        edges[edge->from].push_back(edge);
        if (edge->reverse() != nullptr) {
            edge->reverse()->id = edgeCount;
            edges[edge->reverse()->from].push_back(edge->reverse());
        }
        if (edge->transposed() != nullptr) {
            edges[edge->transposed()->from].push_back(edge->transposed());
            edge->transposed()->id = edgeCount;
            if (edge->transposed()->reverse() != nullptr) {
                edges[edge->transposed()->reverse()->from].push_back(edge->transposed()->reverse());
                edge->transposed()->reverse()->id = edgeCount;
            }
        }
        edgeCount++;
    }
};

typedef FlowEdge<ll> LongFlowEdge;
typedef WeightedEdge<ll> LongWeightedEdge;
typedef FlowEdge<int> IntFlowEdge;
typedef WeightedEdge<int> IntWeightedEdge;
typedef BidirectionalWeightedEdge<ll> LongBiWeightedEdge;
typedef BidirectionalWeightedEdge<int> IntBiWeightedEdge;


//#pragma comment(linker, "/STACK:200000000")

class TaskD {
public:
    void solve(istream &inp, ostream &outp) {
        Input in(inp);
        Output out(outp);

        int n = in.readInt();
        arri u, v;
        in.readArrays(n - 1, u, v);
        decreaseByOne(u, v);

        mod = MODF;

        struct result {
            modint eatBefore;
            modint eatUp;
            modint eatAfter;

            result(const modint &eatBefore, const modint &eatUp, const modint &eatAfter) : eatBefore(eatBefore),
                                                                                           eatUp(eatUp),
                                                                                           eatAfter(eatAfter) {}
        };

        Graph<IntBiWeightedEdge> graph(n);
        for (int i : Range(n - 1)) {
            graph.addEdge(new IntBiWeightedEdge(u[i], v[i], i));
        }

        for (int i : Range(n)) {
            sort(all(graph.edges[i]), [](IntBiWeightedEdge *a, IntBiWeightedEdge *b) -> bool {
                return a->weight < b->weight;
            });
        }

        function<result(int, int)> dfs = [&](int vert, int last) -> result {
            vector<result> res;
            for (auto e : graph.edges[vert]) {
                if (e->to != last) {
                    res.push_back(dfs(e->to, vert));
                }
            }
            modint mult = 1;
            for (const auto &r : res) {
                mult *= r.eatBefore + r.eatAfter;
            }
            modint before = 0;
            modint up = 0;
            modint after = 0;
            int at = 0;
            bool isAfter = false;
            for (auto e : graph.edges[vert]) {
                if (e->to == last) {
                    up = mult;
                    isAfter = true;
                } else {
                    mult *= (res[at].eatBefore + res[at].eatAfter).inverse();
                    if (isAfter) {
                        after += res[at].eatAfter * mult;
                    } else {
                        before += res[at].eatAfter * mult;
                    }
                    mult *= res[at].eatUp + res[at].eatBefore;
                    at++;
                }
            }
            after += mult;
            return result(before, up, after);
        };
        result res = dfs(0, -1);
        out.printLine(res.eatBefore + res.eatAfter);
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    TaskD solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}