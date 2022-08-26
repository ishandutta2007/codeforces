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

template <typename T>
T minim(T& was, T cand) {
    return was = min(was, cand);
}

template <typename T>
T maxim(T& was, T cand) {
    return was = max(was, cand);
}

template <typename T, typename U>
void decreaseByOne(vector<pair<T, U> >& v) {
    for (auto& p : v) {
        p.first--;
        p.second--;
    }
}

void decreaseByOne() {}

template <typename T, class...Vs>
void decreaseByOne(vector<T>& arr, Vs&...vs) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        arr[i]--;
    }
    decreaseByOne(vs...);
}





template <typename D>
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

    template <typename T, class...Vs>
    void initArrays(int n, vector<T>& arr, Vs&...vs) {
        arr.resize(n);
        initArrays(n, vs...);
    }

    void readImpl(int i) {}

    template <typename T, class...Vs>
    void readImpl(int i, vector<T>& arr, Vs&...vs) {
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

    vector<int> readIntArray(int size) {
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
    vector<T> readArray(int n) {
        vector<T> res;
        res.reserve(n);
        for (int i = 0; i < n; i++) {
            res.push_back(readType<T>());
        }
        return res;
    }



    template <class...Vs>
    void readArrays(int n, Vs&...vs) {
        initArrays(n, vs...);
        for (int i = 0; i < n; i++) {
            readImpl(i, vs...);
        }
    }

    template<typename U, typename V>
    vector<pair<U, V> > readArray(int n) {
        vector<pair<U, V> > res;
        res.reserve(n);
        for (int i = 0; i < n; i++) {
            res.push_back(readType<U, V>());
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
    ostream& out;

    template<typename T> void printSingle(const T& value) {
        out << value;
    }

    template<typename T> void printSingle(const vector<T>& array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }
    template<typename T, typename U> void printSingle(const pair<T, U>& value) {
        out << value.first << ' ' << value.second;
    }

public:
    Output(ostream& out) : out(out) {
        out << fixed << setprecision(12);
    }

    void print() {}

    template<typename T, typename...Targs>
    void print(const T& first, const Targs... args) {
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


//#pragma comment(linker, "/STACK:200000000")

class TaskD {
public:
	void solve(istream& inp, ostream& outp) {
        Input in(inp);
        Output out(outp);

        int n = in.readInt();
        auto a = in.readIntArray(n);

        vector<vi> parts;
        parts.emplace_back(1, a[0]);
        for (int i : Range(1, n)) {
            if (a[i] > parts.back().back()) {
                parts.back().push_back(a[i]);
            } else {
                parts.emplace_back(1, a[i]);
            }
        }
        size_t answer = 0;
        for (int i : Range(parts.size())) {
            maxim(answer, parts[i].size());
            if (i + 1 < parts.size() && parts[i].size() > 1 && parts[i + 1].size() > 1 && (parts[i].back() < parts[i + 1][1] || parts[i][parts[i].size() - 2] < parts[i + 1][0])) {
                maxim(answer, parts[i].size() + parts[i + 1].size() - 1);
            }
        }
        out.printLine(answer);
	}
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	TaskD solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}