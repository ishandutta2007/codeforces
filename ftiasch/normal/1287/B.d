import std.algorithm;
import std.conv : to;
import std.container;
import std.numeric : gcd;
import std.range;
import std.stdio;
import std.string;
import std.typecons : Tuple, tuple;

void main() {
    int n, m;
    readf!"%d %d\n"(n, m);
    auto s = new string[n];
    int res = 0;
    int[string] set;
    auto buf = new char[m];
    for (int i = 0; i < n; ++i) {
        s[i] = readln.chomp;
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < m; ++k) {
                buf[k] = s[i][k] == s[j][k] ? s[i][k] : 66 ^ s[i][k] ^ s[j][k];
            }
            res += set.get(cast(string) buf, 0);
        }
        set[s[i]] = 1;
    }
    writeln(res / 2);
}