#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,pl[100005],st[100005],cnt,top,f[100005];
//priority_queue<int,vector<int>,greater<int> > q;
int main() {
	cin>>n;
	for(int i=1,x;i<=2*n;i++){
		char opt;
		cin>>opt;
		if(opt=='+')st[++top]=++cnt;
		else {
			cin>>x;
			if(!top)return puts("NO"),0;
			if(x<f[st[top]])return puts("NO"),0;
			pl[st[top]]=x;
			top--;
			f[st[top]]=max(f[st[top]],max(f[st[top+1]],x));
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)cout<<pl[i]<<' ';
}