// testest

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
 
public class E {
 
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node();
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			int c=fs.nextInt();
			if (c==0) {
				nodes[b].inRed.add(nodes[a]);
			}
			else {
				nodes[b].inBlue.add(nodes[a]);
			}
		}
		nodes[n-1].redHit=nodes[n-1].blueHit=true;
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		nodes[n-1].dist=0;
		bfs.add(nodes[n-1]);
		while (!bfs.isEmpty()) {
			Node next=bfs.removeFirst();
			for (Node from:next.inRed) {
				if (from.redHit) continue;
				from.redHit=true;
				
				if (from.blueHit) {
				    from.dist=next.dist+1;
					bfs.add(from);
					from.color=0;
				}
				else {
					from.color=1;
				}
			}
			
			for (Node from:next.inBlue) {
				if (from.blueHit) continue;
				from.blueHit=true;
				
				if (from.redHit) {
				    from.dist=next.dist+1;
					bfs.add(from);
					from.color=1;
				}
				else {
					from.color=0;
				}
			}
		}
		PrintWriter out=new PrintWriter(System.out);
		if (nodes[0].redHit && nodes[0].blueHit) {
			out.println(nodes[0].dist);
		}
		else {
			out.println(nodes[0].dist);
		}
		for (Node nn:nodes)
			out.print(nn.color);
		out.println();
		out.close();
	}
 
	static class Node {
		ArrayList<Node> inRed=new ArrayList<>(), inBlue=new ArrayList<>();
		boolean redHit=false, blueHit=false;
		int color=0;
		int dist=-1;
	}
	
	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
 
	
}