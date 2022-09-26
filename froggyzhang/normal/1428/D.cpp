#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 100010
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
int n,T;
int a[N],c[N],matched[N];
vector<pair<int,int> > ans;
vector<int> st;
int main(){
	n=read();
	for(int i=1;i<=n;++i) {
		a[i]=read();
	}
	int las=0,now=0;
	for(int i=1;i<=n;++i) {
		if(a[i]==3){
			las=i;
			if(now)ans.emplace_back(now,i);
			ans.emplace_back(++now,i);
			c[i]=now;
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]==2){
			st.push_back(i);
			ans.emplace_back(++now,i);
			c[i]=now;
		}
		else if(a[i]==1){
			if(st.empty()){
				ans.emplace_back(++now,i);
			}
			else{
				ans.emplace_back(c[st.back()],i);
				st.pop_back();
				matched[i]=1;
			}
		}
	}
	if(!st.empty())return !printf("-1\n");
	if(las){
		bool flag=0;
		for(int i=las+1;i<=n;++i) {
			if(a[i]>0&&!matched[i]) {
				ans.emplace_back(c[las],i);
				flag=1;break;
			}
		}
		if(!flag)return !printf("-1\n");
	}
	printf("%d\n",(int)ans.size());
	for(auto [x,y]:ans){
		printf("%d %d\n",x,y);
	}
	return 0;
}