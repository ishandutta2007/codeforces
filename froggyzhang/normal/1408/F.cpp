#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
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
int n,lim;
vector<pair<int,int> > ans;
inline int Get(){
	int x=1;
	while(x<n)x<<=1;
	return x>>1;
}
void Solve(int x){
	for(int p=2;p<=lim;p<<=1){
		int len=p>>1;
		for(int k=0;k<lim;k+=p){
			for(int i=k;i<k+len;++i){
				int a=i,b=i+len;
				if(a<=n&&b<=n){
					if(x){
						ans.emplace_back(n-a,n-b);
					}
					else{
						ans.emplace_back(a+1,b+1);
					}
				} 
			}
		}
	}
}
int main(){
	n=read();
	lim=Get();
	Solve(0),Solve(1);
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d %d\n",x.first,x.second);
	}
	return 0;
}