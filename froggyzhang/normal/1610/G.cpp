#include<bits/stdc++.h>
using namespace std;
#define N 300020
typedef long long ll;
int a[N],n,nxt[N];
char s[N];
bool cmp(int i,int j){
	while(i<=n&&j<=n&&s[i]==s[j])i=nxt[i+1],j=nxt[j+1];
	if(i<=n&&j<=n)return s[i]<=s[j];
	return i>n&&j<=n;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	stack<int> st;
	st.push(n+1);
	nxt[n+1]=n+1;
	for(int i=n;i>=1;--i){
		nxt[i]=i;
		if(s[i]==')'){
			st.push(i);	
		}
		else{
			st.pop();
			if(st.empty())st.push(i);
			else if(cmp(i,st.top()))st.top()=i;
			else nxt[i]=st.top();	
		}
	}
	for(int i=1;i<=n;i=nxt[i+1]){
		cout<<s[i];
	}
	return 0;
}