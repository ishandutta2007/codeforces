#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 4000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,x,fr,x0,L,R,len,l[N],f[N];
string s1[N],s2[N],ss,p,p1;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	rep(i,1,n){
		cin>>s1[i];l[i]=s1[i].length()-1;
	}
	rep(i,1,n)cin>>s2[i];
	rep(i,1,n)if(s1[i]!=s2[i]){
		if(fr){
			rep(j,0,l[i])if(s1[i][j]!=s2[i][j]){x=j;break;}
			rep(j,0,L)if(x-j<0||s1[i][x-j]!=s1[fr][x0-j]||s2[i][x-j]!=s2[fr][x0-j]){
				L=j-1;break;
			}
			rep(j,0,R)if(x+j>l[i]||s1[i][x+j]!=s1[fr][x0+j]||s2[i][x+j]!=s2[fr][x0+j]){
				R=j-1;break;
			}
		}else{fr=i;
			rep(j,0,l[i])if(s1[i][j]!=s2[i][j]){x0=j;break;}
			L=x0;R=l[i]-x0;
		}
	}
	if(L==-1){cout<<"NO\n";return 0;}
	rep(i,x0-L,x0+R)p=p+s1[fr][i],p1=p1+s2[fr][i];
	len=p.length()-1;f[0]=-1;
	rep(i,1,len){
		for(x=f[i-1];~x;x=f[x])
			if(p[i-1]==p[x])break;
		f[i]=x+1;
	}
	rep(i,1,n){x=0;
		rep(j,0,l[i]){
			while(~x&&p[x]!=s1[i][j])x=f[x];x++;
			if(x>len){ss=s1[i];
				rep(k,0,len)ss[j-len+k]=p1[k];
				if(ss!=s2[i]){
					cout<<"NO\n";return 0;
				}break;
			}
		}
		if(x<=len&&s1[i]!=s2[i]){
			cout<<"NO\n";return 0;
		}
	}
	cout<<"YES\n"<<p<<'\n'<<p1<<'\n';
}