#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pld pair<ld,ld>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define FORE(i,w) for(__typeof(w.begin())i=w.begin();i!=w.end();++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
#define deb(x) cerr<<#x<<" = "<<x<<"\n"
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}
const int inf=1e9+5;
const int nax=1000123;

int k,ile[2],licz[2];
ll wymog;
int w[2][nax][3];
ll t[55][12];

int pro()
{
    cin>>k>>wymog>>ile[0]>>ile[1];
    k--;
    t[0][0]=t[0][4]=t[0][5]=1;
    t[1][1]=1;
    t[1][4]=t[1][5]=2;
    for(int i=2;i<55;++i){
        RE(z,12)t[i][z]=t[i-1][z]+t[i-2][z];
        if(t[i-2][5]==1 && t[i-1][4]==2)t[i][2]++; // A-B
        if(t[i-2][5]==2 && t[i-1][4]==1)t[i][3]++; // B-A
        if(t[i-2][5]==2 && t[i-1][4]==2)t[i][9]++; // BB
        if(t[i-2][5]==1 && t[i-1][4]==1)t[i][8]++; // AA
        t[i][4]=t[i-2][4];
        t[i][5]=t[i-1][5];
    }
    //RE(i,12)deb(t[4][i]);
    RE(id,2){
        RE(i,ile[id]+1)if(i%2==0){
            w[id][licz[id]][0]=0;
            w[id][licz[id]][1]=0;
            w[id][licz[id]][2]=i/2;
            licz[id]++;
        }
        RE(i,ile[id])if(i%2==0){
            w[id][licz[id]][0]=1;
            w[id][licz[id]][1]=0;
            w[id][licz[id]][2]=i/2;
            licz[id]++;
        }
        RE(i,ile[id])if(i%2==0){
            w[id][licz[id]][0]=0;
            w[id][licz[id]][1]=1;
            w[id][licz[id]][2]=i/2;
            licz[id]++;
        }
        RE(i,ile[id]-1)if(i%2==0){
            w[id][licz[id]][0]=1;
            w[id][licz[id]][1]=1;
            w[id][licz[id]][2]=i/2;
            licz[id]++;
        }
    }
    //RE(i,12)deb(t[k][i]);
    RE(i,licz[0])RE(j,licz[1]){
        ll S=0LL;
        // w[0][i][], w[1][j][]
        // t[k][]
        S+=w[0][i][2]*t[k][0]+w[1][j][2]*t[k][1]; // inside
        if(w[0][i][0]&&w[0][i][1])S+=t[k][8]; //aa
        if(w[1][j][0]&&w[1][j][1])S+=t[k][9]; //bb
        if(w[0][i][0]&&w[1][j][1])S+=t[k][3]; //ba
        if(w[0][i][1]&&w[1][j][0])S+=t[k][2]; //ab
        if(S==wymog){
            int n=ile[0],m=ile[1];
            if(w[0][i][0]){
                cout<<"C";
                n--;
            }
            while(w[0][i][2]--){
                cout<<"AC";
                n-=2;
            }
            if(w[0][i][1]){
                RE(_,n-1)cout<<"X";
                cout<<"A";
            }
            else RE(_,n)cout<<"X";
            cout<<endl;
            //---------------------
            if(w[1][j][0]){
                cout<<"C";
                m--;
            }
            while(w[1][j][2]--){
                cout<<"AC";
                m-=2;
            }
            if(w[1][j][1]){
                RE(_,m-1)cout<<"X";
                cout<<"A";
            }
            else RE(_,m)cout<<"X";
            cout<<endl;
            return 0;
        }
    }
    cout<<"Happy new year!";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int z=1;
    //cin>>z;
    RI(_,z)pro();
    return 0;
}