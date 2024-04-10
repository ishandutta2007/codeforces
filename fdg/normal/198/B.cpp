#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <map>

using namespace std;

char c[2][100005];

int t[200005],h[200005],tm[200005],size;
bool used[2][100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d\n",&n,&k);
    gets(c[0]); gets(c[1]);
    t[0]=0; h[0]=0; tm[0]=0; size=1; used[0][0]=true;
    for(int i=0;i<size;++i) {
        int T=t[i],H=h[i],TM=tm[i];
        if (H>0&&!used[T][H-1]&&TM<H-1&&c[T][H-1]!='X') {
            used[T][H-1]=true;
            t[size]=T; h[size]=H-1; tm[size++]=TM+1;
        }
        if (!used[T][H+1]&&c[T][H+1]!='X') {
            if (H+1>=n) {
                puts("YES");
                return 0;
            }
            used[T][H+1]=true;
            t[size]=T; h[size]=H+1; tm[size++]=TM+1;
        }
        if (H+k>=n||!used[T^1][H+k]&&c[T^1][H+k]!='X') {
            if (H+k>=n) {
                puts("YES");
                return 0;
            }
            used[T^1][H+k]=true;
            t[size]=T^1; h[size]=H+k; tm[size++]=TM+1;
        }
    }
    puts("NO");
    return 0;
}