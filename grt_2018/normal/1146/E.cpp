#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 100*1000+1;
int n,q,R,log2n;
int arrx[nax];
int T[(1<<19)];

void change(int&x,int&type) {
    if(type==2) {
        if(x==3) x=2;
        else if(x==2) x=3;
        else x = 1-x;
    }
    else if(type==1||type==0) x=type;
}

void propagate(int x) {
    change(T[2*x],T[x]);
    change(T[2*x+1],T[x]);
    T[x]= 3;
}

void update(int a,int b,int type) {
    a+=R; b+=R;
    for(int i=log2n; i>0; i--) {
        propagate(a/(1<<i));
        propagate(b/(1<<i));
    }
    change(T[a],type); change(T[b],type);
    while(a/2!=b/2) {
        if(a%2==0) {
            change(T[a+1],type);
        }
        if(b%2==1) {
            change(T[b-1],type);
        }
        a/=2;
        b/=2;
    }
}

int query(int a) {
    a+=R;
    for(int i=log2n; i>0; i--) {
        propagate(a/(1<<i));
    }
    int w = 1;
    if(a-R<nax) w=0;
    change(w,T[a]);
    while(a>1) {
        a/=2;
        change(w,T[a]);
    }
    return w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0; i<n;i++) {
        cin>>arrx[i];
    }
    R = (1<<18);
    log2n = 18;
    for(int i=1; i<2*R;i++) T[i]=3;
    for(int i=0; i<q;i++) {
        char s;
        int x;
        cin>>s>>x;
        if(s=='>'&&x==0) {
			update(0,2*nax-1,0);
		}
		else if(s=='<'&&x==0) {
			update(0,2*nax-1,1);
		}
        else if(s=='>'&&x>0) {
            update(x+1+nax,2*nax-1,0);
            update(0,nax-x-1,0);
        }
        else if(s=='<'&&x<0) {
            update(0,nax+x-1,1);
            update(nax-x+1,2*nax-1,1);
        }
        else if(s=='<'&&x>0) {
            update(x+nax,2*nax-1,1);
            update(0,nax-x,1);
            update(nax-x+1,x+nax-1,2);
        }
        else {
            update(0,nax+x,0);
            update(nax-x,2*nax-1,0);
            update(nax+x+1,nax-x-1,2);
        }
    }
    for(int i=0; i<n;i++) {
        int w = query(nax+arrx[i]);
        if(w==1) cout<<abs(arrx[i])<<" ";
        else cout<<-abs(arrx[i])<<" ";
    }
}