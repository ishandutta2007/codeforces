#include<bits/stdc++.h>
using namespace std;
#define N 303
#define y2 ysgh
typedef long long ll;
int n,m;
deque<char> a[N][N],b[N][N];
vector<tuple<int,int,int,int> > Solve(deque<char> a[N][N]){
	vector<tuple<int,int,int,int> > ans;
	auto Move=[&](int x1,int y1,int x2,int y2)->void{
		ans.emplace_back(x1,y1,x2,y2);
		a[x2][y2].push_front(a[x1][y1].back());
		a[x1][y1].pop_back();
	};
	auto Change=[&](int x,int y,int t)->void{
		if(t){
			Move(x,y,2,x^2?y:(y==1?2:1));
		}
		else{
			Move(x,y,1,x^1?y:(y==1?2:1));
		}
	};
	static int cnt[N][N];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cnt[i][j]=a[i][j].size();
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			while(cnt[i][j]--)Change(i,j,a[i][j].back()=='1');	
		}
	}
	for(int i=1;i<=2;++i){
		for(int j=2;j<=m;++j){
			while(!a[i][j].empty())Move(i,j,i,1);
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			string s;
			cin>>s;
			for(int k=0;k<(int)s.length();++k){
				a[i][j].push_back(s[k]);	
			}		
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			string s;
			cin>>s;
			for(int k=0;k<(int)s.length();++k){
				b[i][j].push_front(s[k]);	
			}		
		}
	}
	auto A=Solve(a);
	auto B=Solve(b);
	for(auto &[x1,y1,x2,y2]:B){
		swap(x1,x2),swap(y1,y2);
	}
	reverse(B.begin(),B.end());
	A.insert(A.end(),B.begin(),B.end());
	cout<<A.size()<<'\n';
	for(auto [x1,y1,x2,y2]:A){
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<'\n';
	}
	return 0;
}