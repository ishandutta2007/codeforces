#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
int main(){
    int n;
    cin>>n;
    tuple <int,int,ll> seq[n];
    for(int i=0;i<n;i++){
        long long int a;
        cin>>a;
        get<2>(seq[i])=a;
        get<0>(seq[i])=0;
        get<1>(seq[i])=0;
        while(a%2==0){
            a/=2;
            get<0>(seq[i])++;
        }
        while(a%3==0){
            a/=3;
            get<1>(seq[i])--;
        }
    }
    sort(seq,seq+n);
    for(int i=0;i<n;i++){
        cout<<get<2>(seq[i])<<" ";
    }
}