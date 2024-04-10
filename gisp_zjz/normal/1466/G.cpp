#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
const int M=1000000007;
char t[maxn],s[maxn],w[maxn];
int n,q,m,p2[maxn],ans[maxn];
int cnt[26][maxn];
struct node{
    int id,cof;
};
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void work(int id,int l,int r,string &A){
	if (l>r) return;
    if (A.size()==1){
		add(ans[id],cnt[A[0]-'a'][r]);
		add(ans[id],M-1ll*cnt[A[0]-'a'][l-1]*p2[r-l+1]%M);
        return;
    }
    int len=A.size();
    for (int o=0;o<=1;o++){
		bool flag=1;
		for (int i=o;i<len;i+=2) flag&=A[i]==t[l];
		if (flag){
			string B="";
			for (int i=o^1;i<len;i+=2) B+=A[i];
			work(id,l+1,r,B);
		}
    }
}
int main(){
	p2[0]=1;for (int i=1;i<maxn;i++) p2[i]=p2[i-1]*2%M;
	scanf("%d%d",&n,&q);
	scanf("%s",s); m=strlen(s); s[m]='-';
	for (int i=m+1;i<maxn;i++) s[i]=s[i-m-1];
	scanf("%s",t+1);
	for (int i=1;i<=n;i++){
		for (int j=0;j<26;j++) cnt[j][i]=cnt[j][i-1]*2%M;
		add(cnt[t[i]-'a'][i],1);
	}
	for (int i=0;i<q;i++){
		int k; scanf("%d%s",&k,w);
		int len=strlen(w);
		for (int j=0;j<m+1;j++){
            bool flag=0;
            for (int k=0;k<len;k++) if (s[k+j]!='-'&&s[k+j]!=w[k]){
				flag=1;
				break;
            }
            if (!flag){
                string A="";
                for (int k=0;k<len;k++) if (s[k+j]=='-') A+=w[k];
                if (A.size()){
                    work(i,1,k,A);
                } else {
					add(ans[i],p2[k]);
                }
            }
		}
		printf("%d\n",ans[i]);
	}
	return 0;
}