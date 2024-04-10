#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n;
class Union_Set{
public:
	int f[N];
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;
	}
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
}S;
struct Range{
	int c,l,r,id;
}a[N];
void work(){
	sort(a+1,a+n+1,[&](Range a,Range b){return a.r==b.r?a.c<b.c:a.r<b.r;});
	static Range st[N];
	static int top;
	top=0;
	for(int i=1;i<=n;++i){
		if(a[i].c){
			if(top){
				Range tp=st[top];
				while(top&&st[top].r>=a[i].l){
					
					S.Merge(a[i].id,st[top].id);
					--top;
				}
				if(st[top].id^tp.id)st[++top]=tp;
			}
		}
		else{
			st[++top]=a[i];
		}
	}
	sort(a+1,a+n+1,[&](Range a,Range b){return a.l==b.l?a.c<b.c:a.l>b.l;});
	top=0;
	for(int i=1;i<=n;++i){
		if(a[i].c){
			if(top){
				Range tp=st[top];
				while(top&&st[top].l<=a[i].r){
					S.Merge(a[i].id,st[top].id);
					--top;
				}
				if(st[top].id^tp.id)st[++top]=tp;
			}
		}
		else{
			st[++top]=a[i];
		}
	}
}
void Solve(){
	cin>>n;
	S.init(n);
	for(int i=1;i<=n;++i){
		cin>>a[i].c>>a[i].l>>a[i].r;
		a[i].id=i;
	}
	work();
	for(int i=1;i<=n;++i){
		a[i].c^=1;
	}
	work();
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=S.getf(i)==i;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}