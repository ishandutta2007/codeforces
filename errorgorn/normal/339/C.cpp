#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int m;
bool arr[11];
vector<int> fin;
int memo[1005][12][25];
bool dp(int turn,int last, int delta){
    if (turn==m) return true;
    if (delta>=10 || delta<=-10) return false;
    if (memo[turn][last][delta+12]) return memo[turn][last][delta+12]==1;
    bool can=false;
    for (int x=1;x<=10;x++){
        if (!arr[x] || x==last) continue;
        if (turn&1){
            if (delta-x<0){
                can|=dp(turn+1,x,delta-x);
            }
        }
        else{
            if (delta+x>0){
                can|=dp(turn+1,x,delta+x);
            }
        }
    }
    if (can) memo[turn][last][delta+12]=1;
    else memo[turn][last][delta+12]=2;
    return can;
}
int main(){
    cin>>s>>m;
    for (int x=0;x<10;x++){
        if (s[x]=='1') arr[x+1]=true;
    }

    if (!dp(0,11,0)){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int last=-1,delta=0;
    for (int turn=0;turn<m-1;turn++){
        for (int x=1;x<=10;x++){
            if (!arr[x] || x==last) continue;
            if (turn&1){
                if (delta-x<0 && dp(turn+1,x,delta-x)){
                    printf("%d ",x);
                    last=x,delta-=x;
                    break;
                }
            }
            else{
                if (delta+x>0 && dp(turn+1,x,delta+x)){
                    printf("%d ",x);
                    last=x;
                    delta+=x;
                    break;
                }
            }
        }
    }
    for (int x=1;x<=10;x++){
        if (!arr[x] || x==last) continue;
        if (!(m&1)){
            if (delta-x<0){
                printf("%d ",x);
                return 0;
            }
        }
        else{
            if (delta+x>0){
                printf("%d ",x);
                return 0;
            }
        }
    }
}