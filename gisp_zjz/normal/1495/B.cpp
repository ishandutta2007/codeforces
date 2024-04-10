#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e5+12;
vector<int> A;
int _,n,a[maxn],l[maxn],r[maxn],h,cnt;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=a[n+1]=n+1;
    for (int i=1;i<=n;i++) l[i]=(a[i]>a[i-1])?l[i-1]+1:0;
    for (int i=n;i>=1;i--) r[i]=(a[i]>a[i+1])?r[i+1]+1:0;
    for (int i=1;i<=n;i++) h=max(h,max(l[i],r[i]));
    for (int i=1;i<=n;i++){
		if (l[i]==h) ++cnt;
		if (r[i]==h) ++cnt;
    }
    if (cnt>3) {puts("0");return 0;}
    int ans=0;
    for (int i=1;i<=n;i++){
		if (l[i]==h&&r[i]==h&&h%2==0) ans+=(cnt==2);
		/*
        if (l[i]==h&&r[i]==h-1){
        	bool ok=(cnt==1);
            if (h&1) ok=0;
            int p=i-h-(h-1);
            if (p>=1&&r[p]==h-1) ok=0;
            ans+=ok;
        }
        if (l[i]==h-1&&r[i]==h){
			bool ok=(cnt==1);
			if (h&1) ok=0;
			int p=i+h+(h-1);
			if (p<=n&&l[p]==h-1) ok=0;
			ans+=ok;
        }
        */
    }
	printf("%d\n",ans);
	return 0;
}