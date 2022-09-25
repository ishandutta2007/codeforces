#include<bits/stdc++.h>
using namespace std;
#define N 5005
#define NO {cout<<"-1\n";return 0;}
int n;
struct node{
	int d,u;
}a[N];
vector<pair<int,int> > ans;
void reduce(){
	while(n&&!a[n].d)--n;
}
void adde(int x,int y){
	ans.emplace_back(a[x].u,a[y].u);
	--a[x].d,--a[y].d;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].d;
		a[i].u=i;
	}
	while("myh has no jb!"){
		sort(a+1,a+n+1,[&](node a,node b){return a.d>b.d;});
		reduce();
		if(!n)break;
		if(n==1)NO;
		if(n==2){
			if(a[1].d==1&&a[2].d==1){
				adde(1,2);
				break;
			}
			else NO;
		}
		if(a[n].d==2){
			if(a[1].d==2){
				for(int i=1;i<=n;++i){
					adde(i,i%n+1);
				}
			}
			else if(a[n-1].d==2){
				adde(1,n),adde(1,n-1),adde(n-1,n);
			}
			else NO;
		}
		else if(a[n].d==1){
			for(int j=n-1;j>=1;--j){
				if(a[j].d>1&&a[j].d&1){
					adde(n,j);
					break;
				}
			}
			if(a[n].d){
				if(a[1].d==1)NO;
				adde(1,n);
			}
		}
		else{
			NO;
		}
	}
	cout<<ans.size()<<'\n';
	for(auto t:ans){
		cout<<2<<' '<<t.first<<' '<<t.second<<'\n';
	}
	return 0;
}