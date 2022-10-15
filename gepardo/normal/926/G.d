import std.stdio;
import std.algorithm;
import std.array;

int main()
{
    int n;
	scanf("%d", &n);
	int x = 0, y = 0;
	for (int z, i = 0; i < n; i++) {
		scanf("%d", &z);
		if (z % 2 == 1) x = x + 1;
			else y = y + 1;
	}
	int ans;
	if (x < y) ans = x;
	else {
		ans = y;
		x = x - y;
		ans = ans + x / 3;
	}
    writeln(ans);
    return 0;
}