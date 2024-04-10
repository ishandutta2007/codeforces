#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;i--)
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=40;
int n,m,a[N],mid;
int f[1<<20],tot,mx;
void dfs(int s,int now){
	mx=max(mx,now);
	if(s==mid+1){
		f[++tot]=now;
	} else {
		dfs(s+1,(now+a[s])%m);
		dfs(s+1,now);
	}
}
void Dfs(int s,int now){
//	cout << s << " " << now << endl;
	mx=max(mx,now);
	if(s==n+1){
		int t=lower_bound(f+1,f+tot+1,m-now-1)-f;
		mx=max(mx,(f[t]+now)%m),t--;
		mx=max(mx,(f[t]+now)%m);
	} else {
		Dfs(s+1,(now+a[s])%m);
		Dfs(s+1,now);
	}
}
int main(){
	n=rd(),m=rd();
	rep(i,1,n)a[i]=rd();
	mid=(n+1)/2;
	dfs(1,0);
	sort(f+1,f+tot+1);
//	cout<<tot<<endl;
	Dfs(mid+1,0);
	cout<<mx<<endl;
}