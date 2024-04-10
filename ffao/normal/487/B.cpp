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

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n, s, l;
int arr[110000];
int filaGrande[110000];
int filaPequena[110000];
int iniP, fimP, iniG, fimG;

int con[110000];
int dp[110000];

int main() {
    scanf("%d %d %d", &n, &s, &l);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    con[n-1] = n;
    filaGrande[fimG++] = n-1;
    filaPequena[fimP++] = n-1;
    
    for (int i = n-2; i >= 0; i--) {
        con[i] = con[i+1];
        
        int bustBig = arr[i] + s + 1;
        int st = iniG, ed = fimG-1;
        while (st < ed) {
            int mid = (st+ed+1)/2;
            if (arr[filaGrande[mid]] < bustBig) ed = mid-1;
            else st = mid;
        }
        if (arr[filaGrande[st]] >= bustBig) con[i] = min(con[i], filaGrande[st]-1);

        bustBig = arr[i] - s - 1;
        st = iniP;
        ed = fimP-1;
        while (st < ed) {
            int mid = (st+ed+1)/2;
            if (arr[filaPequena[mid]] > bustBig) ed = mid-1;
            else st = mid;
        }
        if (arr[filaPequena[st]] <= bustBig) con[i] = min(con[i], filaPequena[st]-1);
    
        while (iniP != fimP && arr[i] < arr[filaPequena[fimP-1]]) fimP--;
        filaPequena[fimP++] = i;

        while (iniG != fimG && arr[i] > arr[filaGrande[fimG-1]]) fimG--; 
        filaGrande[fimG++] = i;
    }

    iniP = 0; fimP = 0;
    filaPequena[fimP++] = n;
    dp[0] = -1;

    for (int i = n-1; i >= 0; i--) {
        int st = iniP;
        int ed = fimP-1;
        while (st < ed) {
            int mid = (st+ed)/2;
            if (filaPequena[mid] > con[i]+1) st = mid+1;
            else ed = mid;
        }
        if (filaPequena[st] <= con[i]+1 && filaPequena[st] >= i + l) {
            dp[i] = dp[filaPequena[st]] + 1;
            filaPequena[fimP++] = i;
        }
    }
    
    printf("%d\n", dp[0]);
}