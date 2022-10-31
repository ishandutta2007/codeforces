import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner s=new Scanner(System.in);
		String str=s.nextLine();
		boolean q=false;
		String out="";
		for(int i=0;i<str.length();i++){
			if(q){
				if(str.charAt(i)=='\"'){
					q=false;System.out.println("<"+out+">");
					out="";
				}
				else out+=str.charAt(i);
			}else{
				if(str.charAt(i)=='\"')q=true;
				else if(str.charAt(i)==' '){
					if(!out.equals("")){
						System.out.println("<"+out+">");out="";
					}
				}else out+=str.charAt(i);
			}
		}
		if(!out.equals("")){
			System.out.println("<"+out+">");
		}
	}
}