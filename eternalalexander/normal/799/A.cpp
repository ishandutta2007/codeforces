#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
inline void chkmin(int &x,int y) {
	if(y<x) x=y;
}
inline void chkmax(int &x,int y) {
	if(y>x) x=y;
}
const int N=1e6+5;
int n,t,k,d;
int main(){
    cin>>n>>t>>k>>d;
    if(n%k) n=((n+k-1)/k)*k;
    int x=n/k,y=x*t-1;
    int z=(y-d)/t+y/t;
    puts(z>=x?"YES":"NO");
    return 0;
}