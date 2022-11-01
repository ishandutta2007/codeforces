#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int expo(int a, int b) {
    if(!b) return 1;
    if(b & 1) return 1LL * a * expo(1LL * a * a % MOD, b >> 1) % MOD;
    return expo(1LL * a * a % MOD, b >> 1);
}

int inv_mod(int x) { return expo(x, MOD - 2);}

int i2 = inv_mod(2), i10 = inv_mod(10);

struct number {
    int v, p;
    number(int v, int p) : v(v), p(p) {}
};

number concat(number a, number b) {
    return number((1LL * a.v * b.p + b.v) % MOD, 1LL * a.p * b.p % MOD);
}

int remainder(string& str, int mod) {
    int rem = 0;
    for(char c : str) {
        assert(c >= '0' && c <= '9');
        rem = (10LL * rem + (c - '0')) % mod;
    }
    return rem;
}

number parse(string& str, int &pos);

number c(int l, int r, int k, int p10eL, int rem_l, int rem_r) {
    int prod = expo(p10eL, (rem_r - 1 + MOD - 1) % (MOD - 1));
    int FR, FL;

    if(k == 1) {
        FR = 1LL * r * (r + 1) % MOD * i2 % MOD;
        FL = 1LL * l * (l - 1 + MOD) % MOD * i2 % MOD;
    } else {
        int kr = expo(k, rem_r), kl1 = expo(k, (rem_l - 1 + MOD - 1) % (MOD - 1)), ik1 = inv_mod((k - 1 + MOD) % MOD);
        FR = (1LL * r * kr % MOD * ik1 % MOD
                - 1LL * kr * ik1 % MOD * ik1 % MOD
                + MOD) % MOD;

        FL = (1LL * (l - 1 + MOD) * kl1 % MOD * ik1 % MOD
                - 1LL * kl1 * ik1 % MOD * ik1 % MOD
                + MOD) % MOD;
    }

    return number(1LL * prod * (FR - FL + MOD) % MOD, expo(p10eL, (rem_r - rem_l + 1 + MOD - 1) % (MOD - 1)));
}

number C(number l, number r, string& str_l, string& str_r) {
    if(str_l.size() == str_r.size()) {
        return c(l.v, r.v, inv_mod(l.p), l.p, remainder(str_l, MOD - 1), remainder(str_r, MOD - 1));
    } else {
        int mid  = 0, mid_rem = 0, rem_l = remainder(str_l, MOD - 1), rem_r = remainder(str_r, MOD - 1);
        for(char c : str_l) {
            mid = (10LL * mid + 9) % MOD;
            mid_rem = (10LL * mid_rem + 9) % (MOD - 1);
        }

        int k = inv_mod(l.p), p10eL = l.p;
        number ret = c(l.v, mid, k, p10eL, rem_l, mid_rem);
        for(int i = str_l.size() + 1; i < str_r.size(); i++) {
            k = 1LL * k * i10 % MOD;
            p10eL = 10LL * p10eL % MOD;

            l.v = (mid + 1) % MOD;
            rem_l = (mid_rem + 1) % (MOD - 1);

            mid = (10LL * mid + 9) % MOD;
            mid_rem = (10LL * mid_rem + 9) % (MOD - 1);

            ret = concat(ret, c(l.v, mid, k, p10eL, rem_l, mid_rem));
        }

        k = 1LL * k * i10 % MOD;
        p10eL = 10LL * p10eL % MOD;

        l.v = (mid + 1) % MOD;
        rem_l = (mid_rem + 1) % (MOD - 1);

        ret = concat(ret, c(l.v, r.v, k, p10eL, rem_l, rem_r));
        return ret;
    }
}

number rep(number x, number y, string& str_x) {
    if(y.p == 1) { /// 10^L % MOD == 1
        return number(1LL * x.v * y.v % MOD, 1);
    } else {
        int rem = remainder(str_x, MOD - 1);
        int new_pot = expo(y.p, rem);
        return number(1LL * y.v * ((new_pot - 1 + MOD) % MOD) % MOD * inv_mod((y.p - 1 + MOD) % MOD) % MOD, new_pot);
    }
}

number parse_term(string& str) {
    number a1(0, 1), a2(0, 1);
    int which = 0; /// 0: x | 1: x-y | 2: x(y)
    string t1, t2;

    for(char c : str) {
        if(which == 0) {
            if(c == '-') which = 1;
            else if(c == '(') which = 2;
            else {
                assert(c >= '0' && c <= '9');
                a1 = concat(a1, number(c - '0', 10));
                t1 += c;
            }
        } else if(which == 1) {
            assert(c >= '0' && c <= '9');
            a2 = concat(a2, number(c - '0', 10));
            t2 += c;
        } else {
            t2 += c;
        }
    }

    if(which == 0) return a1;
    else if(which == 1) return C(a1, a2, t1, t2);
    else {
        assert(false); /// shouldnt happen anymore
        //t2.pop_back(); /// last bracket
        //a2 = parse(t2);
        //return rep(a1, a2, t1);
    }

}

/// expression
number parse(string& str, int &pos) {
    string tmp;
    number ret(0, 1), a1(0, 1), a2(0, 1);
    int brackets = 0;

    for(; pos < str.size();) {
        char c = str[pos];
        if(c == '+' && brackets == 0) {
            ret = concat(ret, parse_term(tmp));
            tmp = "";
            pos++;
        } else {
            if(c == '(') {
                a1 = parse_term(tmp);
                a2 = parse(str, ++pos);
                ret = concat(ret, rep(a1, a2, tmp));
                tmp = "";
            }
            else if(c == ')') {
                pos++;
                break;
            }
            else {
                tmp += c;
                pos++;
            }
        }

    }

    ret = concat(ret, parse_term(tmp));
    return ret;
}


char s[100010];
string str;

int main() {
    scanf("%s", s); str = s;

    int pos = 0;
    number ans = parse(str, pos);
    printf("%d\n", ans.v);
    return 0;
}