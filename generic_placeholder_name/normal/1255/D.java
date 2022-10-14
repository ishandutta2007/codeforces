import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    //f you CollegeBoard for making me write in Java
	    Scanner input = new Scanner(System.in);
	    String dict = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
	    int q = input.nextInt();
	    while(q-->0) {
	        int r = input.nextInt();
        	int c = input.nextInt();
        	int k = input.nextInt();
        	int s=0;
        	char[][] mat = new char[r][c];
        	char[][] ans = new char[r][c];
        	for(int i=0; i<r; i++) {
        	    mat[i] = input.next().toCharArray();
        	    for(char tmp: mat[i]) if(tmp=='R') s++;
        	}
        	boolean rev=true;
        	int sz=s/k;
        	int lim=s%k;
        	int part=0;
        	int curr=0;
        	int psz; if(part<lim) psz=sz+1; else psz=sz;
        	for(int i=0; i<r; i++) {
        	    rev^=true;
        	    if(rev) {
        	        for(int j=0; j<c/2; j++) {
                        char tmp=mat[i][j]; mat[i][j]=mat[i][c-j-1]; mat[i][c-j-1]=tmp;
                    }
        	    }
        	    for(int j=0; j<c; j++) {
                    if(mat[i][j]=='R') curr++;
                    if(curr>psz) {
                        part++; curr=1;
                        if(part<lim) psz=sz+1; else psz=sz;
                    }
                    ans[i][j]=dict.charAt(part);
        	    }
        	    if(rev) {
        	        for(int j=0; j<c/2; j++) {
                        char tmp=ans[i][j]; ans[i][j]=ans[i][c-j-1]; ans[i][c-j-1]=tmp;
                    }
        	    }
        	}
        	for(int i=0; i<r; i++) {
        	    for(int j=0; j<c; j++) System.out.print(ans[i][j]);
        	    System.out.println("");
        	}
	    }
	}
}