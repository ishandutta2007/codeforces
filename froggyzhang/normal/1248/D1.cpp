#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
#define N 611
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
int n,x,y,ans;
stack<int> st;
char s[N<<1],a[N<<1];
int solve(int x,int y){
	int l,r=n,las=0;
	int w=0;
	memcpy(s,a,sizeof(a));
	while(!st.empty())st.pop();
	for(l=1;l<=n;l++){
		//if(l==n)goto p;
		if(s[l]=='('){
			st.push(1);
		}
		else{
			if(!st.empty()){
				st.pop();
			}
			else{
				//p:
				/*for(int i=n+1;i<=n+l;i++){
					s[i]=s[i-n];
				}*/
				las=l;
				//r=n+l;
				
			}
		}
	}
	while(!st.empty())st.pop();
	l=las;r=l+n;
	for(int i=n+1;i<=n+l;i++){
		s[i]=s[i-n];
	}
	for(l++;l<=r;l++){
		if(s[l]=='('){
			st.push(1);
		}
		else{
			if(!st.empty()){
				st.pop();
				if(st.empty())w++;
			}
			else{
				return 0;
			}
		}
	}
	if(!st.empty())return 0;
	return w;
}
int main(){
	n=read();
	scanf("%s",a+1);
	if(n&1){
		cout<<0<<endl<<"1 1"<<endl;
		return 0;
	}
	int cnt=0; 
	for(int i=1;i<=n;i++){
		if(a[i]==')')cnt++;
	}
	if(cnt*2!=n){
		cout<<0<<endl<<"1 1"<<endl;
		return 0;
	}
	x=y=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			swap(a[i],a[j]);
			int t=solve(i,j);
			if(t>ans){
				ans=t,x=i,y=j;
			}
			swap(a[i],a[j]);
		}
	}
	cout<<ans<<endl<<x<<" "<<y<<endl;
	return 0;
}
/*
16
()))(()))())((((
*/