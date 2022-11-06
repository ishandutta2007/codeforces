#include<bits/stdc++.h>
using namespace std;
long long t,n,x[200005];
vector<long long>v[2];
inline long long read(){
    register long long num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
}
int main(){
	t=read();
	while(t--){
		n=read(),v[0].clear(),v[1].clear();
	    for(register int i=0;i<n;i++){
		    x[i]=read();
		    if((x[i]&1)!=(i&1))v[i&1].push_back(x[i]);
	    }	
	    printf("%d\n",(v[0].size()==v[1].size())?v[0].size():-1);
	}
}