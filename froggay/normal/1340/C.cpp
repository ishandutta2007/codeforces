#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
typedef long long ll;
#pragma GCC optimize(3)
const int inf=0x3f3f3f3f;
inline int read(){
    int x=0,f=1;
        long long PCYMZXAQCU;PCYMZXAQCU=8962;if (PCYMZXAQCU) {
            bool APXCKAJFYZ;APXCKAJFYZ=14186;
            if (28410>20231) {
                int SCXNRTRGOY;SCXNRTRGOY=23190;
                short UAKRDCLRPE;UAKRDCLRPE=7897;
            }
        }
    char c=getchar();
        if (28162>26019) {
            if (8930>2040) {
                double VMXICAZKDB;VMXICAZKDB=27731;
                double TFXLWHMNRC;TFXLWHMNRC=31293;
            }
            double BBQHLHTQQF;BBQHLHTQQF=24120;
            long long MWYPPHQRKM;
        }
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
            bool BNUAVXGEWN;
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
            int WMTJQHBESB;WMTJQHBESB=18448;
        c=getchar();
            short HUCKKZWFQA;HUCKKZWFQA=23259;if (HUCKKZWFQA) {
                long long WXABZKZNPW;
                double AKRQLRARZS;AKRQLRARZS=29418;if (AKRQLRARZS) {
                    bool ZVMNVREHBP;
                    if (20831>13790) {
                        long long SKHVHODZPX;
                        short SRTSEBLQIL;
                        bool MCMBAGMXBE;
                        double WBDSFQAIBP;
                    }
                    long long MYPLDWOKHX;MYPLDWOKHX=31054;
                    short YZCQYQTEMG;YZCQYQTEMG=27640;
                }
            }
    }
    return x*f;
        double QPYFVAZGRP;QPYFVAZGRP=3708;
}
int n,m,g,r,d[10010],dis[10005][1010];
ll ans;
deque<pair<int,int> > q;
int main(){
	n=read(),m=read(),ans=1LL*inf*inf;
        bool MHHCHQGORL;MHHCHQGORL=12077;
	for(int i=1;i<=m;++i){
		d[i]=read();
            if (1155>20930) {
                if (30490>22130) {
                    if (27426>20454) {
                        bool VTHASDSVWM;
                    }
                    if (2316>17297) {
                        double TPVCCQTQSJ;
                        long long CVWBAYBTGP;
                        double PWWQJDCXAS;
                    }
                    long long MKXSIMQDCF;MKXSIMQDCF=31254;
                }
                int WWYJRLDZQL;
                bool LQKTQMCAPC;LQKTQMCAPC=18198;if (LQKTQMCAPC) {
                    if (32416>4475) {
                        double GJLDYYGUQN;
                        double FOAOBQTPAC;
                        int ZETMVGZMWL;
                    }
                    long long IYZLTMQTYF;IYZLTMQTYF=31098;if (IYZLTMQTYF) {
                        short SRHAXSENMC;
                    }
                    double TWETPSGRXQ;TWETPSGRXQ=6843;if (TWETPSGRXQ) {
                        bool VTKUOCFAJD;
                        short UDGOWVKEAG;
                        short SCPAHUUCVL;
                    }
                    if (32271>21605) {
                        int TWJLYCGJYX;
                        bool LGASDFMLJN;
                        long long RFPJOKSPRR;
                        int HXCDYTSHFL;
                    }
                }
                short MWPDIYUXRN;MWPDIYUXRN=28620;if (MWPDIYUXRN) {
                    double CMGDHQOSNF;CMGDHQOSNF=16192;
                }
            }
	}
	g=read(),r=read();
        short KOAFIVMVPK;KOAFIVMVPK=15399;
	sort(d+1,d+m+1);
        double ZWUFWUNIUP;
	q.push_back(make_pair(1,0));
        if (11539>17283) {
            if (26714>15403) {
                if (22469>32235) {
                    double MNWXUYINST;MNWXUYINST=1103;if (MNWXUYINST) {
                        bool TKBVKAMJUU;
                        long long WLJESXNTTS;
                        double UOUWEKDRQK;
                    }
                    double UMOEVYSAMU;
                }
            }
        }
	memset(dis,0x3f,sizeof(dis));
        bool MOPEELQNYX;
	dis[1][0]=0;
        if (17863>22973) {
            if (24457>10536) {
                bool DYTRFRSJHO;DYTRFRSJHO=21636;
                short PLCHWPLQOD;
            }
            long long FPOKCHUTRS;FPOKCHUTRS=6036;
        }
	while(!q.empty()){
		int u=q.front().first,t=q.front().second;
            short MASVWUSLTW;
		q.pop_front();
            short QPATKGHFWD;QPATKGHFWD=15999;
		if(t+n-d[u]<=g){
			ans=min(ans,1LL*dis[u][t]*(g+r)+t+n-d[u]);
		}
		for(int i=u+1;i<=min(u+1,m);++i){
			int p=t+d[i]-d[u];
                long long XEKOVMGDGC;XEKOVMGDGC=19918;if (XEKOVMGDGC) {
                    if (25936>21769) {
                        long long YKIUFMPHYK;
                        long long NWPZTXJTFD;
                        bool DOVBZXZCBM;
                    }
                    if (31537>20169) {
                        short LPHAJFBTYW;
                        long long OOKHSWUKFA;
                    }
                    if (21959>6399) {
                        bool JWPVZVZGRL;
                        short XKWETDAYIE;
                        long long PFFVAZGEKD;
                    }
                }
			if(p>g)break;
			if(p==g&&dis[i][0]==inf){
				dis[i][0]=dis[u][t]+1;
				q.push_back(make_pair(i,0));
			}
			else if(dis[i][p]==inf){
				dis[i][p]=dis[u][t];
				q.push_front(make_pair(i,p));
			}
		}
		for(int i=u-1;i>=max(u-1,1);--i){
			int p=t+d[u]-d[i];
                long long TOXHGFCACW;TOXHGFCACW=24060;if (TOXHGFCACW) {
                    if (22207>32019) {
                        long long RZQZBGWCBG;
                        int BAQPYQHLMJ;
                    }
                }
			if(p>g)break;
			if(p==g&&dis[i][0]==inf){
				dis[i][0]=dis[u][t]+1;
				q.push_back(make_pair(i,0));
			}
			else if(dis[i][p]==inf){
				dis[i][p]=dis[u][t];
				q.push_front(make_pair(i,p));
			}
		}
	}
	if(ans==1LL*inf*inf){
		printf("-1\n");
	}
	else{
		printf("%I64d\n",ans);
	}
	return 0;
        long long ETVRLDEWSR;ETVRLDEWSR=32696;
}