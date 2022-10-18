/* Writen by Filip Hlasek 2011 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAXN 111

using namespace std;

int Wa[MAXN],Wd[MAXN],Wr[MAXN],Ws[MAXN],Aa[MAXN],Ad[MAXN],Ar[MAXN],As[MAXN],Oa[MAXN],Od[MAXN],Or[MAXN],Os[MAXN],a,d,r,si;
int N,M,SI,W,A,O,bestW,bestA,bestO;
string Wn[MAXN],An[MAXN],On[MAXN],n,t,h;

typedef struct resident{
  string name,type,home;
  int bonus;
  bool used;
}R;

R res[1111],g[1111],s[1111],p[1111];
int G,S,P;
vector<string> tmp;
vector<string> Gn,Sn,Pn;

bool mycompare(R x,R y){ return x.bonus>y.bonus; }

int main(int argc, char *argv[]){
  int i,j;
  SI=0; W=0; A=0; O=0; G=0; S=0; P=0;
  scanf("%d",&N);
  FOR(i,N){
    cin >> n >> t >> a >> d >> r >> si;
    SI+=si;
    if(t[0]=='w'){ Wa[W]=a; Wd[W]=d; Wr[W]=r; Ws[W]=si; Wn[W++]=n; }
    if(t[0]=='a'){ Aa[A]=a; Ad[A]=d; Ar[A]=r; As[A]=si; An[A++]=n; }
    if(t[0]=='o'){ Oa[O]=a; Od[O]=d; Or[O]=r; Os[O]=si; On[O++]=n; }
  }
  scanf("%d",&M);
  FOR(i,M){
    cin >> n >> t >> a >> h;
    res[i].name=n; res[i].type=t; res[i].home=h; res[i].bonus=a;
    if(t[0]=='g'){ g[G].name=n; g[G].type=t; g[G].home=h; g[G++].bonus=a; }
    if(t[0]=='s'){ s[S].name=n; s[S].type=t; s[S].home=h; s[S++].bonus=a; }
    if(t[0]=='p'){ p[P].name=n; p[P].type=t; p[P].home=h; p[P++].bonus=a; }
  }
  sort(g,g+G,mycompare);
  sort(s,s+S,mycompare);
  sort(p,p+P,mycompare);
  int best=0,sum;
  if(SI==M){
    bestW=0;
    best=0;
    FOR(i,W){
      sum=Wa[i];
      FOR(j,M) if(Wn[i]==res[j].home&&res[j].type[0]=='g') sum+=res[j].bonus;
      if(sum>best){
        best=sum;
        bestW=i;
      }
    }
    FOR(j,M) if(Wn[bestW]==res[j].home) tmp.push_back(res[j].name);
    cout << Wn[bestW] << " " << tmp.size();
    FOR(i,tmp.size()) cout << " "<< tmp[i];
    printf("\n");
    bestA=0;
    best=0;
    FOR(i,A){
      sum=Ad[i];
      FOR(j,M) if(An[i]==res[j].home&&res[j].type[0]=='s') sum+=res[j].bonus;
      if(sum>best){
        best=sum;
        bestA=i;
      }
    }
    tmp.clear();
    FOR(j,M) if(An[bestA]==res[j].home) tmp.push_back(res[j].name);
    cout << An[bestA] << " " << tmp.size();
    FOR(i,tmp.size()) cout << " "<< tmp[i];
    printf("\n");
 
    bestO=0;
    best=0;
    FOR(i,O){
      sum=Or[i];
      FOR(j,M) if(On[i]==res[j].home&&res[j].type[0]=='p') sum+=res[j].bonus;
      if(sum>best){
        best=sum;
        bestO=i;
      }
    }
    tmp.clear();
    FOR(j,M) if(On[bestO]==res[j].home) tmp.push_back(res[j].name);
    cout << On[bestO] << " " << tmp.size();
    FOR(i,tmp.size()) cout << " "<< tmp[i];
    printf("\n");
    return 0;
  }
  bestW=0;
  best=0;
  FOR(i,W){
    sum=Wa[i];
    FOR(j,min(G,Ws[i])) sum+=g[j].bonus;
    if(sum>best){
      best=sum;
      bestW=i;
      Gn.clear();
      FOR(j,min(G,Ws[i])) Gn.push_back(g[j].name);
    }
  }
  bestA=0;
  best=0;
  FOR(i,A){
    sum=Ad[i];
    FOR(j,min(S,As[i])) sum+=s[j].bonus;
    if(sum>best){
      best=sum;
      bestA=i;
      Sn.clear();
      FOR(j,min(S,As[i])) Sn.push_back(s[j].name);
    }
  }
  bestO=0;
  best=0;
  FOR(i,O){
    sum=Or[i];
    FOR(j,min(P,Os[i])) sum+=p[j].bonus;
    if(sum>best){
      best=sum;
      bestO=i;
      Pn.clear();
      FOR(j,min(P,Os[i])) Pn.push_back(p[j].name);
    }
  }

  FOR(i,Gn.size()) FOR(j,M) if(res[j].name==Gn[i]) res[j].used=true;
  FOR(i,Sn.size()) FOR(j,M) if(res[j].name==Sn[i]) res[j].used=true;
  FOR(i,Pn.size()) FOR(j,M) if(res[j].name==Pn[i]) res[j].used=true;
  FOR(i,M) if(!res[i].used&&Gn.size()!=Ws[bestW]){ Gn.push_back(res[i].name); res[i].used=true; }
  FOR(i,M) if(!res[i].used&&Sn.size()!=As[bestA]){ Sn.push_back(res[i].name); res[i].used=true; }
  FOR(i,M) if(!res[i].used&&Pn.size()!=Os[bestO]){ Pn.push_back(res[i].name); res[i].used=true; }

  cout << Wn[bestW] << " " << Gn.size();
  FOR(i,Gn.size()) cout << " "<< Gn[i];
  printf("\n");
  
  cout << An[bestA] << " " << Sn.size();
  FOR(i,Sn.size()) cout << " "<< Sn[i];
  printf("\n");

  cout << On[bestO] << " " << Pn.size();
  FOR(i,Pn.size()) cout << " "<< Pn[i];
  printf("\n");

  return 0;
}