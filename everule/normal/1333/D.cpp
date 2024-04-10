#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
void solve(){
   int n,k;
   cin>>n>>k;
   string seq;
   cin>>seq;
   vector<int> wait(n,-1);
   for(int i=1;i<n;i++){
       if(seq[i]=='L'){
           wait[i]=max(0,wait[i-1]+1);
       }
       else{
           wait[i]=wait[i-1]-1;
       }
   }
   #ifdef debugwait
   for(int i=0;i<n;i++){
       if(seq[i]=='L'){
            cout<<wait[i]<<" ";
       }
   }
   cout<<"\n";
   #endif
   vector<vector<int>> turns(n*n);
   int lcount=0;
   ll maxturns=0;
   int minturns=0;
   for(int i=0;i<n;i++){
       if(seq[i]!='L'){
           continue;
       }
       for(int j=0;j<i-lcount;j++){
            turns[wait[i]+j].pb(i-j);
            ++maxturns;
            minturns=max(wait[i]+j+1,minturns);
       }
       ++lcount;
   }
   if(k<minturns || k>maxturns){
       std::cout<<"-1\n";
       return;
   }
   for(int i=0;i<minturns;i++){
       if(turns[i].size() + minturns - i - 1<=k){
           for(int j=0;j<turns[i].size();j++){
               std::cout<<"1 "<<turns[i][j]<<"\n";
               --k;
           }
           continue;
       }
       if(minturns-i==k){
           --k;
           std::cout<<turns[i].size()<<" ";
           for(int j=0;j<turns[i].size();j++){
               std::cout<<turns[i][j]<<" ";
           }
           std::cout<<"\n";
           continue;
       }
       int j=0;
       for(j=0;j<turns[i].size();j++){
           if(k==minturns-i){
               break;
           }
           --k;
           std::cout<<"1 "<<turns[i][j]<<"\n";
       }
       --k;
       std::cout<<turns[i].size()-j<<" ";
       for(;j<turns[i].size();j++){
           std::cout<<turns[i][j]<<' ';
       }
       std::cout<<"\n";
   }
}
int main(){
    //FILE *input=freopen("input.txt","r",stdin);
    //FILE *output=freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    //fclose(input);
    //fclose(output);
}