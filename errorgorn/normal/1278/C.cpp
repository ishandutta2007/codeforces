#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int n;
int arr[200005];
map<int,int> fw,bw;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d",&n);
        for (int x=0;x<n*2;x++) scanf("%d",&arr[x]);
        
        fw.clear();
        bw.clear();
        fw[0]=n;
        bw[0]=n;
        
        int curr=0;
        for (int x=0;x<n;x++){
            if (arr[x]==1) curr++;
            else curr--;
            fw[curr]=n-x-1;
        }
        
        curr=0;
        for (int x=n*2-1;x>=n;x--){
            if (arr[x]==1) curr--;
            else curr++;
            bw[curr]=x-n;
        }
        
        int ans=2*n;
        for (auto &it:fw){
            if (bw.count(it.first)){
                ans=min(ans,it.second+bw[it.first]);
            }
        }
        
        printf("%d\n",ans);
    }
}