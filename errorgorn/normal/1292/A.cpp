#include <cstdio>
using namespace std;

int n,q;
int blocked=0;

bool lava[2][100005];
bool block[100005];
bool block2[100005];
int main(){
    scanf("%d%d",&n,&q);
    
    int a,b;
    bool bb;
    while (q--){
        scanf("%d%d",&a,&b);
        a--;
        lava[a][b]^=true;
        
        bb=false;
        if (lava[0][b-1] && lava[1][b]) bb=true;
        if (lava[1][b-1] && lava[0][b]) bb=true;
        
        if (block[b-1]!=bb){
            if (bb) blocked++;
            else blocked--;
            block[b-1]=bb;
        }
        
        bb=false;
        if (lava[0][b] && lava[1][b+1]) bb=true;
        if (lava[1][b] && lava[0][b+1]) bb=true;
        
        if (block[b]!=bb){
            if (bb) blocked++;
            else blocked--;
            block[b]=bb;
        }
        
        bb=false;
        if (lava[0][b] && lava[1][b]) bb=true;
        
        if (block2[b]!=bb){
            if (bb) blocked++;
            else blocked--;
            block2[b]=bb;
        }
        
        if (blocked==0) printf("Yes\n");
        else printf("No\n");
    }
}