#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define mt make_tuple
using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    while(t--){
        int cnt[55];
        int tot[2];
        fill(tot,tot+2,0);
        int n;
        scanf("%d",&n);
        int odd=0;
        for(int i = 0;i<n;i++){
            char c[55];
            scanf("%s",c);
            for(int j = 0;c[j]!=0;j++){
                tot[c[j]-'0']++;
            }
            if(strlen(c)%2==1)odd++;
        }
        if(odd==0&&tot[0]%2!=0)printf("%d\n",n-1);
        else printf("%d\n",n);
    }
	return 0;
}