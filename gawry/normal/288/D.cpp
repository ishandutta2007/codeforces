#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int MAX=81000;
int n;
vector<int> s[MAX];
int parent[MAX],cnt[MAX];
void dfs(int cur,int prev){
	parent[cur]=prev;
	cnt[cur]=1;
	for(int i=0;i<s[cur].size();i++)if(s[cur][i]!=prev){
		dfs(s[cur][i],cur);
		cnt[cur]+=cnt[s[cur][i]];
	}
}
int get_cnt(int cur,int prev){
	if(prev==parent[cur])return cnt[cur];
	return n-cnt[prev];
}
typedef long long int64;
inline int64 choose2(int64 n){
	return n*(n-1)/2;
}
vector<int64> t;
int64 go(int begin,int end,int64 add=0){
	int64 ans=0;
	if(begin+4>end){
		for(int i=begin;i<end;i++)for(int j=i+1;j<end;j++){
			ans+=t[i]*t[j]*add;
			for(int k=begin;k<end;k++)if(i!=k&&j!=k){
				ans+=t[i]*t[j]*choose2(t[k]);
			}
		}
	}else{
	//printf("%d,%d\n",begin,end);
		int middle=(begin+end)/2;
		int64 second_left=0,second_right=0,first_left=0,first_right=0;
		for(int i=begin;i<middle;i++){
			first_left+=t[i];
			second_left+=choose2(t[i]);
		}
		for(int i=middle;i<end;i++){
			first_right+=t[i];
			second_right+=choose2(t[i]);
		}
		ans+=go(begin,middle,add+second_right);
		ans+=go(middle,end,add+second_left);
		
		int64 combine_left=0,combine_right=0;
		for(int i=begin;i<middle;i++){
			combine_left+=t[i]*(second_left-choose2(t[i]));
		}
		for(int i=middle;i<end;i++){
			combine_right+=t[i]*(second_right-choose2(t[i]));
		}

		ans+=combine_left*first_right;
		ans+=combine_right*first_left;
		ans+=first_left*first_right*add;
	}
	return ans;
}
main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		s[x].push_back(y);
		s[y].push_back(x);
	}
	dfs(1,0);
//	printf("%d\n",get_cnt(1,0));
	long long ans=0;
	for(int i=1;i<=n;i++){
		int64 total=0;
		t.clear();
		for(int j=0;j<s[i].size();j++){
			int64 subtree=get_cnt(s[i][j],i);
			t.push_back(subtree);
			total+=choose2(subtree);
		}
		for(int j=0;j<t.size();j++){
			int64 subtree=t[j];
			int64 left=total-choose2(subtree);
			ans+=subtree*left;
		}
		ans+=go(0,t.size());
	}
	cout<<ans<<endl;
}