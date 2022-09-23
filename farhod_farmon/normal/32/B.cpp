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
    int a,i;
    string s,t;
    cin>>s;
    a=s.size();
    for( i=0; i<a; i++ ){
        if( s[i]=='-' && s[i+1]=='-' ){
            t+='2';
            i++;
        }
        else if( s[i]=='-' && s[i+1]=='.' ){
            t+='1';
            i++;
        }
        else{
            t+='0';
        }
    }
    cout<<t;
    return 0 ;
}