#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int n,m;
int arr[105][105];
int main(){
    scanf("%d%d",&n,&m);
    for (int x=0;x<m;x++){
        for (int y=0;y<n;y++){
            scanf("%d",&arr[x][y]);
        }
    }
    
    vector<ii> diff;
    vector<int> fin;
    vector<int> aa;
    int delta;
    unsigned int ans=1000000;
    n--;
    for (int x=0;x<n;x++){
        diff.clear();
        fin.clear();
        delta=0;
        for (int y=0;y<m;y++){
            diff.push_back(ii(arr[y][n]-arr[y][x],y));
            delta+=diff.back().first;
        }
        
        sort(diff.begin(),diff.end());
        while (delta>0){
            delta-=diff.back().first;
            fin.push_back(diff.back().second);
            diff.pop_back();
        } 
        if (fin.size()<ans){
            ans=fin.size();
            aa=fin;
        }
    }
    
    printf("%u\n",ans);
    for (int x=0;x<ans;x++){
        printf("%d ",aa[x]+1);
    }
}