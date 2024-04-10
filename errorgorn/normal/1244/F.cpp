#include <cstdio>
using namespace std;
int n,k;
char chip[200005];
int pow[200005];
int main(){
    scanf("%d%d",&n,&k);
    getchar();
    for (int x=0;x<n;x++){
        chip[x]=getchar()=='W';
    }
    for (int x=0;x<n;x++){
        if (chip[x]==chip[(x+1)%n]) goto general;
    }
    k%=2;
    for (int x=0;x<n;x++){
        printf("%c",(chip[x]^(k))?'W':'B');
    }
    return 0;
    general:
    for (int x=0;x<n;x++){
        if (chip[x]==chip[(x+1)%n]){
            pow[x]=k;
            pow[(x+1)%n]=k;
        }
    }
    for (int x=0;x<n;x++){
        if (pow[x]-1>pow[(x+1)%n]){
            pow[(x+1)%n]=pow[x]-1;
            chip[(x+1)%n]=chip[x];
        }
    }
    for (int x=0;x<n;x++){
        if (pow[x]-1>pow[(x+1)%n]){
            pow[(x+1)%n]=pow[x]-1;
            chip[(x+1)%n]=chip[x];
        }
    }
    for (int x=n;x>0;x--){
        if (pow[x%n]-1>pow[x-1]){
            pow[x-1]=pow[x%n]-1;
            chip[x-1]=chip[x%n];
        }
    }
    for (int x=n;x>0;x--){
        if (pow[x%n]-1>pow[x-1]){
            pow[x-1]=pow[x%n]-1;
            chip[x-1]=chip[x%n];
        }
    }
    k%=2;
    for (int x=0;x<n;x++){
        if (pow[x]) printf("%c",chip[x]?'W':'B');
        else printf("%c",(chip[x]^(k))?'W':'B');
    }
}