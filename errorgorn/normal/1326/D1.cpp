#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>


struct RNG{
    typedef unsigned long long ull;
    ///taken from http://prng.di.unimi.it/xoshiro256plusplus.c
    ull s[4];

    RNG(ull a, ull b, ull c, ull d){
        ///please seed this with something legit
        s[0]=a,s[1]=b,s[2]=c,s[3]=d;
		
		for (int x=0;x<(1<<10);x++) next();
    }

    static inline ull rotl(const ull x, int k){
        return (x << k) | (x >> (64 - k));
    }


    ull next() {
        const ull result = rotl(s[0] + s[3], 23) + s[0];

        const ull t = s[1] << 17;

        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];

        s[2] ^= t;

        s[3] = rotl(s[3], 45);

        return result;
    }
} rng=*new RNG(274290,264525,151430,275877); ///nice


int base[30]; ///hash for each letter
const int MOD=1000000009; ///maybe need 2 mod if sway
const long long P=179424673;
long long powP[500005]; ///P^x

///stuff for hashing

struct str{
    string s;
    vector<int> h;

    str(){}

    str(string _s){
		//cout<<_s<<endl;
        s=_s;
        h.push_back(base[s[0]-'a']);
        for (int x=1;x<s.size();x++){
            h.push_back((h.back()*P+base[s[x]-'a'])%MOD);
        }
    }

    int roll(int i){ ///[0,i]
        return h[i];
    }

    int roll(int i,int j){ ///[i,j]
        if (i==0) return roll(j);
        return (h[j]-(h[i-1]*powP[j-i+1])%MOD+MOD)%MOD;
    }
};

string s,t;
str f,b;

int main(){
	powP[0]=1;
    for (int x=1;x<500005;x++) powP[x]=(powP[x-1]*P)%MOD;
	
	for (int x=0;x<30;x++) base[x]=rng.next()%MOD;
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>t;
		s="";
		for (int x=0;x<t.size();x++){
			s+=t[x];
			s+='z'+1;
		}
		s.pop_back();
		
		f=str(s);
		reverse(s.begin(),s.end());
		b=str(s);
		reverse(s.begin(),s.end());
		
		int best=-1;
		int A=-2,B=-2,C=-2;
		int l,r;
		for (int x=0;x<s.size();x++){
			int lo=0,hi=min(x,(int)s.size()-1-x)+1,mi;
			
			while (hi-lo>1){
				mi=hi+lo>>1;
				
				if (f.roll(x,x+mi)==b.roll(s.size()-1-x,s.size()-1-x+mi)) lo=mi;
				else hi=mi; 
			}
			
			//cout<<s[x]<<" "<<lo<<endl;
			l=x-lo,r=x+lo;
			//cout<<l<<" "<<r<<endl;
			
			if (l==0 || r==s.size()-1){
				//cout<<"found "<<l<<" "<<r<<endl;
				
				if (r-l>best){
					best=r-l+1;
					A=l,B=r;
					C=-1;
				}
				
			}
			else if (f.roll(0,min(l,(int)s.size()-1-r)-1)==b.roll(0,min(l,(int)s.size()-1-r)-1)){
				//cout<<"found "<<l<<" "<<r<<endl;
				
				
				if ((min(l,(int)s.size()-1-r))*2+r-l>best){
					best=(min(l,(int)s.size()-1-r))*2+r-l;
					A=l,B=r;
					C=min(l,(int)s.size()-1-r);
				}
				
			}	
		}
		
		//cout<<best<<endl;
		//cout<<A<<" "<<B<<" "<<C<<endl;
		
		for (int x=0;x<C;x++) if (s[x]!='{') putchar(s[x]);
		for (int x=A;x<=B;x++) if (s[x]!='{') putchar(s[x]);
		for (int x=s.size()-C;x<s.size();x++) if (s[x]!='{') putchar(s[x]);
		
		putchar('\n');
	}
	
}