#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0) {putchar('-');x=-x;}    if(x>=10)   write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
char s[505],t[505];
int q[505][505];
int a[505],cnt[505];

int main(){
	int T = read();
	while(T--){
		scanf("%s %s", s + 1, t + 1);
		For(i, 0, 25) cnt[i] = 0;
		int len = strlen(s + 1);
		For(i, 1, len)
			q[s[i] - 'A'][++cnt[s[i] - 'A']] = i;
		len = strlen(t + 1);
		bool ok = 1;
		Dow(i, 1, len)
		{
			a[i] = q[t[i] - 'A'][cnt[t[i] - 'A']--];
			if(cnt[t[i] - 'A'] < 0) {ok = 0; break;}
		}
		For(i, 1, len)	
			For(j, i + 1, len)
				if(a[i] > a[j])
					ok = 0;
		if(ok) puts("YES");
		else puts("NO");
	}
}