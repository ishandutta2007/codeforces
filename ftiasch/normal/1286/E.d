import std.stdio : stdin, write, writeln;

struct Solver {
    this(int n) {
        s = new byte[n], w = new uint[n], fail = new int[n], nextDiff = new int[n],
            stack = new int[n], parent = new int[n], size = new int[n];
    }

    ulong add(int i) {
        fail[i] = -1;
        if (i) {
            int j = i - 1;
            nextDiff[j] = ~fail[j] ? (s[fail[j] + 1] == s[i] ? nextDiff[fail[j]] : fail[j]) : -1;
            while (~j) {
                j = fail[j];
                if (s[j + 1] == s[i]) {
                    fail[i] = j + 1;
                    break;
                }
            }
            for (j = i - 1; ~j;) {
                if (s[j + 1] != s[i]) {
                    int r = findRoot(i - 1 - j);
                    // writeln("remove: ", i - j, " ", i, " ", j);
                    result -= w[r], size[r]--;
                    j = fail[j];
                }
                else {
                    j = nextDiff[j];
                }
            }
        }
        parent[i] = i, size[i] = s[0] == s[i];
        while (top && w[stack[top - 1]] >= w[i]) {
            int j = stack[--top];
            result -= cast(long) size[j] * w[j];
            size[i] += size[j], parent[j] = i;
        }
        stack[top++] = i, result += cast(long) size[i] * w[i];
        // for (i = 0; i < top; ++i) {
        //     write("(", w[stack[i]], " ", size[stack[i]], "),");
        // }
        // writeln();
        return result;
    }

    int findRoot(int u) {
        if (parent[u] != u) {
            parent[u] = findRoot(parent[u]);
        }
        return parent[u];
    }

    byte[] s;
    uint[] w;
    int top = 0;
    ulong result = 0;
    int[] fail, nextDiff, stack, parent, size;
}

void main() {
    import std.bigint : BigInt;
    import std.conv : to;
    import std.string : chomp;

    const int q = stdin.readln.chomp.to!int;
    auto s = new Solver(q);
    BigInt ans = 0;
    for (int i = 0; i < q; ++i) {
        string line = stdin.readln;
        s.s[i] = cast(byte)((line[0] - 'a' + ans) % 26);
        s.w[i] = cast(uint)(line[2 .. $].chomp.to!uint ^ (ans & 0x3FFFFFFF));
        // writeln("append ", cast(char)('a' + s.s[i]), ' ', s.w[i]);
        ans += s.add(i);
        writeln(ans);
    }
}