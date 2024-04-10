#include<cstdio>
#include<vector>
const int N=2E5+7;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
} 

long long a[N],bit[N],n;std::vector<int>v[26];
long long sum(int i)
{
    long long s = 0;
    while (i > 0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
 
void add(long long i, long long x)
{
    while (i <= n){
        bit[i] += x;
        i += i & -i;
    }
}
void solve()
{
    long long ans = 0;
    for (int j= 0; j < n; j++){
        ans += j - sum(a[j]);
        add(a[j], 1);
    }
    printf("%lld\n", ans);
}
int main()
{
    n=read();
    char c;
    while((c=getchar())<64);
    v[c-97].push_back(0);
    for(int i=1;i<n;++i)v[getchar()-97].push_back(i);
    for(int i=0;i<26;++i)
    {
    	int s=v[i].size()-1;
    	for(int j=0;j<=s;++j)a[v[i][j]]=n-v[i][s-j];
	}
	solve();
	return 0;
}