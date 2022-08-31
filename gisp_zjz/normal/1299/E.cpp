#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
const int maxn=805;

int n,A[maxn],a[maxn],pos[maxn],odd[maxn],m3[maxn],m5[maxn],m7[maxn],m4[maxn],m8[maxn];
bool ask(vi a){
    printf("? %d",a.size());
    for (auto x:a) printf(" %d",x);
    puts(""); fflush(stdout);
    char s[5]; scanf("%s",s);
    return s[0]=='1';
    /*
    int sum=0;
    for (auto x:a) sum+=A[x];
    return sum%a.size()==0;
    */
}
void answer(){
    if (a[1]>n/2){
        for (int i=1;i<=n;i++) a[i]=n+1-a[i];
    }
    printf("!");
    for (int i=1;i<=n;i++) printf(" %d",a[i]);
    puts("");
}
void _set(int x,int y){
    a[x]=y; pos[y]=x;
}
void findp(int x){
    assert(x<=n/2);
    vi po;
    for (int i=1;i<=n;i++){
        if (!a[i]){
            vi res; res.clear();
            for (int j=1;j<=n;j++) if (!a[j]&&i!=j) res.pb(j);
            if (ask(res)) po.pb(i);
        }
    }
    assert(po.size()==2);
    if (x>1){
        if (x&1) {
            if (!odd[po[0]]) swap(po[0],po[1]);
        } else {
            if (odd[po[0]]) swap(po[0],po[1]);
        }
    }
    _set(po[0],x);
    _set(po[1],n+1-x);
}
void solve3(){
    memset(m3,-1,sizeof(m3));
    for (int i=1;i<=n;i++) if (!a[i]&&m3[i]==-1){
        vi res=(vi){pos[1],pos[2],i};
        if (ask(res)) m3[i]=(3-(1+2)%3)%3;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m3[i]==-1){
        vi res=(vi){pos[1],pos[3],i};
        if (ask(res)) m3[i]=(3-(1+3)%3)%3;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m3[i]==-1){
        vi res=(vi){pos[2],pos[3],i};
        if (ask(res)) m3[i]=(3-(2+3)%3)%3;
    }
}
void solve5(){
    memset(m5,-1,sizeof(m5));
    for (int i=1;i<=n;i++) if (!a[i]&&m5[i]==-1){
        vi res=(vi){pos[1],pos[2],pos[3],pos[4],i};
        if (ask(res)) m5[i]=(5-(1+2+3+4)%5)%5;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m5[i]==-1){
        vi res=(vi){pos[1],pos[2],pos[3],pos[5],i};
        if (ask(res)) m5[i]=(5-(1+2+3+5)%5)%5;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m5[i]==-1){
        vi res=(vi){pos[1],pos[2],pos[4],pos[5],i};
        if (ask(res)) m5[i]=(5-(1+2+4+5)%5)%5;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m5[i]==-1){
        vi res=(vi){pos[1],pos[3],pos[4],pos[5],i};
        if (ask(res)) m5[i]=(5-(1+3+4+5)%5)%5;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m5[i]==-1){
        vi res=(vi){pos[2],pos[3],pos[4],pos[5],i};
        if (ask(res)) m5[i]=(5-(2+3+4+5)%5)%5;
    }
}
void solve7(){
    memset(m7,-1,sizeof(m7));
    for (int i=1;i<=n;i++) if (!a[i]&&m7[i]==-1){
        vi res=(vi){pos[1],pos[2],pos[3],pos[n-4],pos[n-3],pos[n-2],i};
        if (ask(res)) m7[i]=(7-(1+2+3+n-4+n-3+n-2)%7)%7;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m7[i]==-1){
        vi res=(vi){pos[1],pos[2],pos[4],pos[n-4],pos[n-3],pos[n-2],i};
        if (ask(res)) m7[i]=(7-(1+2+4+n-4+n-3+n-2)%7)%7;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m7[i]==-1){
        vi res=(vi){pos[1],pos[2],pos[5],pos[n-4],pos[n-3],pos[n-2],i};
        if (ask(res)) m7[i]=(7-(1+2+5+n-4+n-3+n-2)%7)%7;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m7[i]==-1){
        vi res=(vi){pos[1],pos[3],pos[5],pos[n-4],pos[n-3],pos[n-2],i};
        if (ask(res)) m7[i]=(7-(1+3+5+n-4+n-3+n-2)%7)%7;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m7[i]==-1){
        vi res=(vi){pos[1],pos[4],pos[5],pos[n-4],pos[n-3],pos[n-2],i};
        if (ask(res)) m7[i]=(7-(1+4+5+n-4+n-3+n-2)%7)%7;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m7[i]==-1){
        vi res=(vi){pos[2],pos[4],pos[5],pos[n-4],pos[n-3],pos[n-2],i};
        if (ask(res)) m7[i]=(7-(2+4+5+n-4+n-3+n-2)%7)%7;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m7[i]==-1){
        vi res=(vi){pos[3],pos[4],pos[5],pos[n-4],pos[n-3],pos[n-2],i};
        if (ask(res)) m7[i]=(7-(3+4+5+n-4+n-3+n-2)%7)%7;
    }
}
void solve8(){
    memset(m4,-1,sizeof(m4));
    for (int i=1;i<=n;i++) if (!a[i]&&!odd[i]){
        vi res=(vi){pos[1],pos[2],pos[3],i};
        if (ask(res)) m4[i]=2; else m4[i]=0;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&odd[i]){
        vi res=(vi){pos[1],pos[2],pos[4],i};
        if (ask(res)) m4[i]=1; else m4[i]=3;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m4[i]==0){
        vi res=(vi){pos[1],pos[2],pos[3],pos[n-3],pos[n-2],pos[n-1],pos[n],i};
        m8[i]=(8-(1+2+3+n-3+n-2+n-1+n)%8)%8;
        if (!ask(res)) m8[i]=(m8[i]+4)%8;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m4[i]==1){
        vi res=(vi){pos[2],pos[3],pos[4],pos[n-3],pos[n-2],pos[n-1],pos[n],i};
        m8[i]=(8-(2+3+4+n-3+n-2+n-1+n)%8)%8;
        if (!ask(res)) m8[i]=(m8[i]+4)%8;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m4[i]==2){
        vi res=(vi){pos[1],pos[3],pos[4],pos[n-3],pos[n-2],pos[n-1],pos[n],i};
        m8[i]=(8-(1+3+4+n-3+n-2+n-1+n)%8)%8;
        if (!ask(res)) m8[i]=(m8[i]+4)%8;
    }
    for (int i=1;i<=n;i++) if (!a[i]&&m4[i]==3){
        vi res=(vi){pos[1],pos[2],pos[4],pos[n-3],pos[n-2],pos[n-1],pos[n],i};
        m8[i]=(8-(1+2+4+n-3+n-2+n-1+n)%8)%8;
        if (!ask(res)) m8[i]=(m8[i]+4)%8;
    }
}
void self_test(){
    for (int i=1;i<=n;i++) A[i]=i;
    random_shuffle(A+1,A+n+1);
    if (A[1]>n/2) for (int i=1;i<=n;i++) A[i]=n+1-A[i];
}
int main(){
    scanf("%d",&n);
    //self_test();
    findp(1); odd[pos[1]]=1;
    for (int i=1;i<=n;i++) if (i!=pos[1]){
        vi res; res.clear();
        res.pb(pos[1]); res.pb(i);
        odd[i]=ask(res);
    }
    //for (int i=1;i<=4;i++)cout<<odd[i]<<' ';cout<<endl;
    if (n<=10){
        for (int i=2;i<=n/2;i++) findp(i);
    } else {
        for (int i=2;i<=5;i++) findp(i);
        solve3(); solve5(); solve7(); solve8();
        for (int i=1;i<=n;i++) if (!a[i]){
            for (int j=1;j<=n;j++)
                if (j%3==m3[i]&&j%5==m5[i]&&j%7==m7[i]&&j%8==m8[i]) {_set(i,j);break;}
        }
    }
    answer();
    //cout << "! ";
    //for (int i=1;i<=n;i++) cout << A[i] << ' '; cout << endl;
    return 0;
}