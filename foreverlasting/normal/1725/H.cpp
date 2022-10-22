#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define gc getchar
#define pli pair<LL,int>
#define pii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
inline int rd(){
    int s=0,w=1,ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
const int N=1e5+10,mxn=1e6+10;
const LL infl=1e18;
int n,cnt,c[3],a[mxn],b[mxn];
int main(){
	n=rd();
	for(int i=1;i<=n;++i) c[a[i]=rd()%3]++;
	if(c[0]<=n/2)
	{
		puts("0");cnt=n/2;
		for(int i=1;i<=n;++i)
			if(!a[i])
				b[i]=1,cnt--;
		for(int i=1;i<=n;++i)
			if(!b[i]&&cnt)
				b[i]=1,cnt--;
		for(int i=1;i<=n;++i) printf("%d",b[i]);puts("");
	}
	else
	{
		puts("2");cnt=n/2;
		for(int i=1;i<=n;++i)
			if(!a[i]&&cnt)
				b[i]=1,cnt--;
		for(int i=1;i<=n;++i) printf("%d",b[i]);puts("");
	}
	return 0;
}