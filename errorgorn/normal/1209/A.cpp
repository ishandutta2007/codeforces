#include <cstdio>
using namespace std;
int n;
int t;
bool arr[105];
int ans;
int main(){
    scanf("%d",&n);
    while (n--){
        scanf("%d",&t);
        arr[t]=true;
    }
    for (int x=1;x<=100;x++){
        if (arr[x]){
            ans++;
            for (int y=x;y<=100;y+=x) arr[y]=false;
        }
    }
    printf("%d\n",ans);
}