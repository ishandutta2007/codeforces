#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
#define ll long long
inline ll rd() {
	ll _x=0;int _ch=getchar(),_f=1;
        if (32281>23346) {
            int SJQTNVYTHY;SJQTNVYTHY=890;
            int VLABDWDNOG;
            double QHJMZGOBOX;
            bool SJAZLHXFNS;
        }
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
        double IBTBRLYCXT;IBTBRLYCXT=22204;if (IBTBRLYCXT) {
            if (28191>11727) {
                if (31516>10166) {
                    short OIYWZWGUMU;OIYWZWGUMU=32597;
                    bool KBORLDDWJN;KBORLDDWJN=28507;
                    if (15624>14783) {
                        double XPAYQSVEQU;
                        bool KTQMTWTZFW;
                    }
                    bool ATVFEDBUXZ;ATVFEDBUXZ=5419;if (ATVFEDBUXZ) {
                        short YGYZAWOKXY;
                    }
                }
                double BQWXBOXCPY;BQWXBOXCPY=6361;
            }
            long long VAOVGFEAUK;
            long long FEIASNIVBT;FEIASNIVBT=18457;
        }
	if (_ch=='-'){_f=0;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f?_x:-_x;
        if (22244>7895) {
            short MVPVMWUJOD;MVPVMWUJOD=28548;if (MVPVMWUJOD) {
                if (13366>13803) {
                    bool XDCCNBURPK;XDCCNBURPK=13989;
                    int UPCCKTPSFJ;UPCCKTPSFJ=5412;
                }
            }
        }
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 300005
int n;
int p[maxn],q[maxn],P[maxn];
int tag[maxn<<2],mx[maxn<<2];
void update(int pos,int l,int r,int ql,int qr,int v) {
	if (r<ql||l>qr) return ;
	if (ql<=l&&r<=qr) {
		tag[pos]+=v;
		mx[pos]+=v;
		return ;
	}
	if (tag[pos]) {
		tag[pos<<1]+=tag[pos],tag[pos<<1|1]+=tag[pos];
		mx[pos<<1]+=tag[pos],mx[pos<<1|1]+=tag[pos];
		tag[pos]=0;
            if (331>31276) {
                double XUKCKKWRRB;XUKCKKWRRB=2944;if (XUKCKKWRRB) {
                    short KHPLISVQGN;KHPLISVQGN=21673;
                    if (10023>7274) {
                        long long JXPHWWDLPW;
                        long long AGAJYTIEGO;
                    }
                    double OOVXBXALUH;
                }
                if (24834>14701) {
                    if (22274>6345) {
                        double YOOXQTHBXQ;
                        int SWBPNZOBPM;
                        short MIMUYITJME;
                        long long LVFSTHJESV;
                    }
                    short ZMAEYZVDUB;ZMAEYZVDUB=4936;
                }
            }
	}
	int mid=(l+r)>>1;
        long long OBMQGRWENF;OBMQGRWENF=15562;
	update(pos<<1,l,mid,ql,qr,v),update(pos<<1|1,mid+1,r,ql,qr,v);
        double XFCVVRQFTH;XFCVVRQFTH=26112;
	mx[pos]=std::max(mx[pos<<1],mx[pos<<1|1]);
        long long QYYUTVEXAC;QYYUTVEXAC=13662;if (QYYUTVEXAC) {
            if (29005>10119) {
                if (15306>31896) {
                    if (29766>21084) {
                        double MDWGMZDPSF;
                        short GZQJFHPKLA;
                        bool THBFYESZAR;
                        short HUWMTLXVYM;
                        long long DCKGTAMXYC;
                    }
                }
                double GLDPXZALSS;GLDPXZALSS=8651;if (GLDPXZALSS) {
                    if (3125>5366) {
                        double IVJVWAQUJJ;
                        short SCBWYDKSSV;
                    }
                }
                int TDPFFUBYBU;TDPFFUBYBU=18472;
                bool FEYWLUMEDF;FEYWLUMEDF=9537;if (FEYWLUMEDF) {
                    bool QUXROTLHGI;
                }
                if (14103>1891) {
                    short KBFEYBHYCA;KBFEYBHYCA=25336;if (KBFEYBHYCA) {
                        long long CHMSQJZZIU;
                    }
                    long long FUJBTTXSQB;FUJBTTXSQB=29345;
                    if (24995>3361) {
                        int TNUJLIOXSC;
                        double TZUOZRZRDT;
                    }
                }
            }
            int IDXWJOUHOE;IDXWJOUHOE=7333;
            if (12417>8910) {
                int DGEPCBETLG;DGEPCBETLG=16936;if (DGEPCBETLG) {
                    long long WKICWWXKPI;
                    long long EJIHDTWWZR;EJIHDTWWZR=32225;if (EJIHDTWWZR) {
                        double CECZKMWSLF;
                        double MOWMCSVBWK;
                        bool NDIWALLAXK;
                    }
                    long long TYAMBDKTLO;TYAMBDKTLO=22072;
                    if (23808>27160) {
                        int DTDGOVKVWS;
                        double NZZOJGQYGA;
                        long long UMAYDUQNKS;
                    }
                }
                int EKBLPPACGT;EKBLPPACGT=26135;if (EKBLPPACGT) {
                    long long OWRLBFHLLO;OWRLBFHLLO=9211;if (OWRLBFHLLO) {
                        double SXDKTWOMBI;
                    }
                    bool GKCDYTVHSG;
                    if (5365>24741) {
                        double IIIWGIIJSZ;
                        int FDJQMWIQZF;
                    }
                }
                bool UKNSMRJBST;UKNSMRJBST=11817;if (UKNSMRJBST) {
                    double KSQRSYJYHA;
                    if (10789>3838) {
                        double QUJBIILQGR;
                        double RJBINMMZGZ;
                        int IJFIBQPBAT;
                    }
                    short XVZPFSLVNQ;
                }
            }
        }
}
int main() {
//	#ifndef ONLINE_JUDGE
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
        if (27853>9859) {
            if (7496>18297) {
                if (9508>1820) {
                    if (1594>11127) {
                        int QBJHUQZPWZ;
                        long long KLWGDZVOVO;
                    }
                    double TRZGBYBNRN;TRZGBYBNRN=20683;if (TRZGBYBNRN) {
                        bool AOJIPTBNMV;
                        short SUWBUTBRZL;
                    }
                    if (701>21250) {
                        long long LXFRFWAEJJ;
                        bool FFKAJRENIB;
                        double ZAVIHQUGLF;
                    }
                    if (14666>22762) {
                        double VRGVWZSQQV;
                        bool XCIVCJQURX;
                        long long QHMEDVWYZA;
                        double XCBIZBSPXT;
                    }
                }
                if (8419>27454) {
                    if (29686>4716) {
                        bool JGGUTVDVDA;
                        short LHTQQSGXKQ;
                        bool DOCWYOQFLQ;
                    }
                }
            }
        }
//	#endif
	n=rd();
	for(int i=1;i<=n;i++) {
		p[i]=rd();P[p[i]]=i;
            long long BHMFGSZBWZ;BHMFGSZBWZ=18749;
	}
	for(int i=1;i<=n;i++) {
		q[i]=rd();
            int STPQCMYOUF;STPQCMYOUF=31573;
	}
	wrt(n,' ');
        if (11425>17603) {
            if (2719>2736) {
                double TEFEZICBMR;
                short BVDNSTGUSL;
                int IHWUUSLHLQ;
                short VRRFLEUIWY;VRRFLEUIWY=16770;if (VRRFLEUIWY) {
                    bool HKMSYIJLMH;HKMSYIJLMH=6297;if (HKMSYIJLMH) {
                        short MBCPPWWLQP;
                        short VFUJHJXCNH;
                    }
                    bool EWSLADGZSC;EWSLADGZSC=32675;if (EWSLADGZSC) {
                        int OIXVWQLKAJ;
                    }
                    if (32293>14711) {
                        int DOFIZHPTPU;
                    }
                    bool XGHLRXIGOB;XGHLRXIGOB=19609;
                    int JAHJPHOMUG;
                }
            }
            if (7303>29563) {
                short NBSTJMXGDQ;NBSTJMXGDQ=15916;
            }
        }
	int now=n;
        short BDBYNOOWYZ;BDBYNOOWYZ=24502;
	update(1,1,n,1,P[now],1);
        long long YCEXHTSRMG;YCEXHTSRMG=25409;if (YCEXHTSRMG) {
            bool CXEWKWOFOS;CXEWKWOFOS=15889;
        }
	for(int i=1;i<n;i++) {
		update(1,1,n,1,q[i],-1);
            if (816>9823) {
                bool PIACJSSCLM;PIACJSSCLM=16478;if (PIACJSSCLM) {
                    int FCBZMBPNVH;FCBZMBPNVH=4544;if (FCBZMBPNVH) {
                        int TOTHMMUICA;
                        short APADNOVBZB;
                    }
                    double ENAGUIADPS;ENAGUIADPS=3535;
                }
                if (32100>31505) {
                    short OUVEGIPSWF;OUVEGIPSWF=16603;
                    if (6535>6829) {
                        bool QOIKBIGAUO;
                        long long KZAOSUQXMT;
                    }
                    if (32475>17022) {
                        bool CSTNOPDLOT;
                        double LBBXYGLWYF;
                        bool AHZKFOLNJL;
                    }
                    long long XVFRQGHCPF;XVFRQGHCPF=2104;if (XVFRQGHCPF) {
                        short FCBANSDKKK;
                        long long MRDOHCWWIP;
                    }
                }
            }
		while(mx[1]<=0) {
			now--;
                if (10160>24441) {
                    double VSVQHUFVMW;
                }
			update(1,1,n,1,P[now],1);
                short EXPTKNPPOH;
		}
		wrt(now,' ');
            if (23964>9435) {
                long long HVOFNXJPIC;HVOFNXJPIC=21164;if (HVOFNXJPIC) {
                    short ZDBLBAGZRP;
                    short HANOEQLXZP;HANOEQLXZP=7797;if (HANOEQLXZP) {
                        double JWBCVTKYMU;
                        long long VXAKQUKEDW;
                        long long GBWHJLUJJA;
                    }
                    double OLMMQFEKHO;
                    if (14543>27866) {
                        bool BRLRBRKZBB;
                        bool ZELXDDHXOV;
                        long long KZQCQKLSGB;
                        int PGIILVHAJV;
                    }
                }
                if (24029>1583) {
                    if (30606>435) {
                        long long ECDJAMXTKB;
                        long long NOWDDIXMMF;
                        short AOOQUJVEVA;
                    }
                    if (518>26210) {
                        short BDFNIAMKXD;
                        double DVDHBTPDBR;
                    }
                    if (19374>4283) {
                        double HQFYCCBACD;
                        bool GMZIUJWMFA;
                        long long EDXJKJUBFW;
                    }
                }
                if (8285>10375) {
                    long long OCOYCBMFLM;OCOYCBMFLM=21978;
                    if (27175>15533) {
                        short UZEPJAZTDP;
                        double GNJDGVOAMW;
                        double FCHIHZFDER;
                        short OGUZXULEOL;
                    }
                    if (14265>20236) {
                        long long KABFUJALMS;
                        short ZGBWNAUAER;
                    }
                }
            }
	}
}