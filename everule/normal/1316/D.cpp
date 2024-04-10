//https://codeforces.com/problemset/problem/1316/D
#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
int n;
inline bool valid(int x){
    return (x>=0 && x<n);
}
void solve(){
    cin>>n;
    pair<int,int> seq[n][n];
    char ans[n][n];
    bool found[n][n];
    bool possible=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]='-';
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            found[i][j]=0;
            cin>>seq[i][j].second>>seq[i][j].first;
            if(seq[i][j]!=mp(-1,-1)){
                --seq[i][j].first;
                --seq[i][j].second;
                ans[seq[i][j].first][seq[i][j].second]='X';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!found[i][j] && ans[i][j]=='X'){
                if(seq[i][j]!=mp(i,j)){
                    possible=0;
                }
                queue<pair<int,int>> tochk;
                tochk.push(mp(i,j));
                found[i][j]=1;
                while(!tochk.empty()){
                    int x=tochk.front().first;
                    int y=tochk.front().second;
                    if(valid(x-1) && !found[x-1][y] && seq[x-1][y]==mp(i,j)){
                        ans[x-1][y]='R';
                        tochk.push(mp(x-1,y));
                        found[x-1][y]=1;
                    }
                    if(valid(x+1) && !found[x+1][y]  && seq[x+1][y]==mp(i,j)){
                        ans[x+1][y]='L';
                        tochk.push(mp(x+1,y));
                        found[x+1][y]=1;                        
                    }
                    if(valid(y+1) && !found[x][y+1]  && seq[x][y+1]==mp(i,j)){
                        ans[x][y+1]='U';
                        tochk.push(mp(x,y+1));
                        found[x][y+1]=1;
                    }    
                    if(valid(y-1) && !found[x][y-1]  && seq[x][y-1]==mp(i,j)){
                        ans[x][y-1]='D';
                        tochk.push(mp(x,y-1));
                        found[x][y-1]=1;                        
                    }
                    tochk.pop();                
                }
            }
            if(!found[i][j] && seq[i][j]==mp(-1,-1)){
                found[i][j]=1;
                queue<pair<int,int>> tochk;
                tochk.push(mp(i,j));
                int x=i,y=j;
                if(valid(x-1) && !found[x-1][y] && seq[x-1][y]==mp(-1,-1)){
                    ans[x-1][y]='R';
                    ans[x][y]='L';
                    tochk.push(mp(x-1,y));
                    found[x-1][y]=1;
                }
                else if(valid(x+1) && !found[x+1][y]  && seq[x+1][y]==mp(-1,-1)){
                    ans[x+1][y]='L';
                    ans[x][y]='R';
                    tochk.push(mp(x+1,y));
                    found[x+1][y]=1;                
                }
                else if(valid(y+1) && !found[x][y+1]  && seq[x][y+1]==mp(-1,-1)){
                    ans[x][y+1]='U';
                    ans[x][y]='D';
                    tochk.push(mp(x,y+1));
                    found[x][y+1]=1;                
                }    
                else if(valid(y-1) && !found[x][y-1]  && seq[x][y-1]==mp(-1,-1)){
                    ans[x][y-1]='D';
                    ans[x][y]='U';
                    tochk.push(mp(x,y-1));
                    found[x][y-1]=1;                        
                }
                else{
                    possible=0;
                    break;
                }
                while(!tochk.empty()){
                    int x=tochk.front().first,y=tochk.front().second;
                    if(valid(x-1) && !found[x-1][y] && seq[x-1][y]==mp(-1,-1)){
                        ans[x-1][y]='R';
                        tochk.push(mp(x-1,y));
                        found[x-1][y]=1;
                    }
                    if(valid(x+1) && !found[x+1][y]  && seq[x+1][y]==mp(-1,-1)){
                        ans[x+1][y]='L';
                        tochk.push(mp(x+1,y));
                        found[x+1][y]=1;                        
                    }
                    if(valid(y+1) && !found[x][y+1]  && seq[x][y+1]==mp(-1,-1)){
                        ans[x][y+1]='U';
                        tochk.push(mp(x,y+1));
                        found[x][y+1]=1;                        
                    }    
                    if(valid(y-1) && !found[x][y-1]  && seq[x][y-1]==mp(-1,-1)){
                        ans[x][y-1]='D';
                        tochk.push(mp(x,y-1));
                        found[x][y-1]=1;                        
                    }
                    tochk.pop();                
                }
            }
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(!found[i][j]){
                possible=0;
            }
        }
    } 
    if(!possible){
        cout<<"INVALID";
    }
    else{
        cout<<"VALID\n";
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                cout<<ans[i][j];
            }
            cout<<'\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}