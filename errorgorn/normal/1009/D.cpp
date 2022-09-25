#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n,m;
vector<ii> fin;

int main(){
    scanf("%d%d",&n,&m);
    if (m<n-1){
        printf("Impossible\n");
        return 0;
    }

    for (int x=2;x<=n;x++){
        m--;
        fin.push_back(ii(1,x));
    }

    for (int x=2;x<=n;x++){
        for (int y=x+1;y<=n;y++){
            if (m==0) goto _end;
            if (__gcd(x,y)==1) fin.push_back(ii(x,y)),m--;
        }
    }
    if (m){
        printf("Impossible\n");
        return 0;
    }
    _end:;
    printf("Possible\n");
    for (vector<ii>::iterator it=fin.begin();it!=fin.end();it++){
        printf("%d %d\n",(*it).first,(*it).second);
    }
}