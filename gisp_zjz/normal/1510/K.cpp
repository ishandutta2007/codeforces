#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=2e3+10;
int p[maxn],a[maxn][maxn],n;
int main(){
	cin >> n;
    for (int i=0;i<n*2;i++) cin >> p[i];
    for (int i=1;i<=n*2;i++){
        if (i%2==0){
			for (int j=0;j<n;j++) swap(p[j*2],p[j*2+1]);
        } else {
			for (int j=0;j<n;j++) swap(p[j],p[j+n]);
        }
        bool flag=1;
        for (int j=0;j<n*2;j++) flag&=(p[j]==j+1);
        if (flag){
			if (n%2==1){
				printf("%d\n",min(n*2-i,i));
			} else {
                printf("%d\n",min(4-i,i));
			}
			return 0;
        }
    }
	puts("-1");
	return 0;
}