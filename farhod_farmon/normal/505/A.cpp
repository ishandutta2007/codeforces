#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>

#define pb push_back
#define lli long long int
#define st string
#define sc scanf
#define pr printf
#define cl clear
#define vlli vector < lli >
#define vs vector < string >
#define vf vector < float >
#define vc vector < char >
#define vi vector < int >
#define fi first
#define se second
#define pllilli pair < lli, lli >
#define pii pair < int, int >

using namespace std;
int main()
{
    string s,t;
    int i,j,cnt=0;
    char c;
    cin>>s;
    for( i=0; i<=s.size(); i++ ){
         for( c='a'; c<='z'; c++ ){
              t="";
              cnt=0;
              for( j=0; j<i; j++ ){
                   t+=s[j];     
              }     
              t+=c;
              for( j=i; j<s.size(); j++ ){
                   t+=s[j];     
              }
              for( j=0; j<t.size()/2; j++ ){
                   if( t[j]==t[t.size()-1-j] ){
                       cnt++;    
                   }     
              }
              if( cnt==t.size()/2 ){
                  cout<<t;
                  //system ( "pause" );
                  return 0;    
              }
         }     
    } 
    cout<<"NA";
    //system ( "pause" );
    return 0;    
}