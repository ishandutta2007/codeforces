//2018.11.24 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int kcz=1e9+7;
const int N=1e6+10;
namespace MAIN{
	int sit[N],dec[N];
    struct PAM{
    	struct Pam{
    		int vis[26],len,fail;
		}pam[N];
		int cnt,las;
		PAM() {pam[0].fail=pam[1].fail=1,pam[cnt=1].len=-1;}
		inline void extend(const res &x,const res &id,const char *str){
			res p=las;
			for(;str[id-pam[p].len-1]!=str[id];p=pam[p].fail);
			if(!pam[p].vis[x]){
				res np=++cnt,q=pam[p].fail;
				for(;str[id-pam[q].len-1]!=str[id];q=pam[q].fail);
				pam[np].len=pam[p].len+2,pam[np].fail=pam[q].vis[x],pam[p].vis[x]=np;
				dec[np]=pam[np].len-pam[pam[np].fail].len;
				sit[np]=(dec[np]==dec[pam[np].fail])?sit[pam[np].fail]:pam[np].fail;
			}
			las=pam[p].vis[x];
		}
	}A;
	char str[N],ch[N];
	int n;
	inline void add(res &x,const res &y){
		x+=y;
		x>=kcz?x-=kcz:1; 
	}
	int f[N],g[N];
    inline void MAIN(){
    	scanf("%s",str+1);
    	n=strlen(str+1);
    	for(res i=1;i<=n;i+=2)ch[i]=str[(i+1)/2];
    	reverse(str+1,str+n+1); 
    	for(res i=2;i<=n;i+=2)ch[i]=str[(i+1)/2];
    	g[0]=1;
    	for(res i=1;i<=n;i++){
    		A.extend(ch[i]-'a',i,ch);
    		for(res j=A.las;j;j=sit[j]){
    			f[j]=g[i-A.pam[sit[j]].len-dec[j]];
    			if(sit[j]!=A.pam[j].fail)add(f[j],f[A.pam[j].fail]);
    			if(i%2==0)add(g[i],f[j]);
			}
		}
		printf("%d\n",g[n]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}