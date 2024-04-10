#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
#define N 200010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n,ok[N];
vector<int> vec[N];
set<int> s;
int main(){
	T=read();
	while(T--){
		n=read();
		s.clear();
		for(int i=1;i<=n;++i){
			ok[i]=0;
			int m=read();
			s.insert(i);
			vec[i].clear();
			for(int j=1;j<=m;++j){
				int x=read();
				vec[i].push_back(x);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<vec[i].size();++j){
				if(s.count(vec[i][j])){
					ok[i]=1;
					s.erase(vec[i][j]);
					break;
				}
			}
		}
		if(!s.empty()){
			printf("IMPROVE\n");
			for(int i=1;i<=n;++i){
				if(!ok[i]){
					printf("%d %d\n",i,*s.begin());
					break;
				}
			}
		}
		else{
			printf("OPTIMAL\n");
		}
	}
	return 0;
}