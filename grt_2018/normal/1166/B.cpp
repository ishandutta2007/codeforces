#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>ii;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

int k;
char tem[5] = {'a','e','i','o','u'};
bool ok;

int main() {
    scanf("%d",&k);
    for(int i=5; i*i<=k; i++) {
        if(k%i==0) {
            ok=1;
            for(int j=0; j<i; j++) {
                int ind = (j)%5;
                for(int ii=0; ii<k/i; ii++) {
                    printf("%c",tem[ind]);
                    ind=(ind+1)%5;
                }
            }
            break;
        }
    }
    if(!ok) printf("-1");
}