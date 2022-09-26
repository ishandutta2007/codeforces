#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 2333
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
int n,a[N],p[N]; 
vector<pair<int,int> > ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read(),p[i]=i;
	}
	sort(p+1,p+n+1,[](int i,int j){return a[i]==a[j]?i<j:a[i]<a[j];});
	for(int i=1;i<n;++i){
		for(int j=2;j<=n;++j){
			if(p[j]<p[j-1]){
				ans.emplace_back(p[j],p[j-1]);
				swap(p[j],p[j-1]);
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d %d\n",x.first,x.second);
	}
	return 0;
}