#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

#define MAXM 1100000

char p[MAXM];  
int pos[MAXM];  
int m, k;
void KMP(){ int i, j=-1; pos[0]=-1; for( i=1 ; i<m ; i++ ){ while( j>=0 && p[j+1]!=p[i] ) j=pos[j]; if( p[j+1]==p[i] ) j++; pos[i]=j; } }

int main() {
    scanf("%d %d", &m, &k);
    scanf("%s", p);
    
    KMP();

    for (int i = 0; i < m; i++) {
        int period = i - pos[i];
        int reps = (i+1) / period;
        
        int lim = (reps % k);
        if (period * reps != i+1) lim++;
        if ((reps - (reps % k) ) / k >= lim ) printf("1");
        else printf("0");
    }

    printf("\n");
}