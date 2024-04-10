#include<cstdio>
using namespace std;
int main() {
int t[6];
for(int i = 0; i < 6; ++i) scanf("%d", &t[i]);
for(int a = 0; a < 2; ++a)
for(int b = 2; b < 4; ++b)
for(int c = 4; c < 6; ++c)
if(t[b]+t[c] <= t[a] && t[b^1] <= t[a^1] && t[c^1] <= t[a^1]) {
puts("YES");
return 0;
}
puts("NO");
return 0;
}