#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define ll long long
#define pn cout<<"NO\n"
#define py cout<<"YES\n" 
int T,i,j,hd,n,k,fl,a[N],mx,x,y,v,st[N],vst[N];
char s[N];
void print(int x){
	if(x>26)print((x-1)/26);
	putchar('a'+((x-1)%26));
} 
int main(){
	ios::sync_with_stdio(false);
	for(i=1;i<=26;++i){
		st[++hd]=i;
	}
	for(i=1;i<=26;++i){
	for(j=1;j<=26;++j)
		st[++hd]=i*26+j;
	}
	for(i=1;i<=26;++i){
	for(j=1;j<=26;++j)
	for(k=1;k<=26;++k) 
		st[++hd]=i*26*26+j*26+k;
	}
	scanf("%d",&T); 
	while(T--){
		scanf("%d%s",&n,s+1);
		for(i=1;i<=n;++i){
			s[i]=s[i]-'a'+1;
			vst[s[i]]=1;
		}
		for(i=1;i<n;++i){
			vst[s[i]*26+s[i+1]]=1;
		}
		for(i=1;i<n-1;++i){
			vst[s[i]*26*26+s[i+1]*26+s[i+2]]=1;
		}
		for(i=1;i<=hd;++i){
			if(!vst[st[i]]){print(st[i]);putchar('\n');break;}
		}for(i=1;i<=n;++i){
			vst[s[i]]=0;
		}
		for(i=1;i<n;++i){
			vst[s[i]*26+s[i+1]]=0;
		}
		for(i=1;i<n-1;++i){
			vst[s[i]*26*26+s[i+1]*26+s[i+2]]=0;
		}
	}
}