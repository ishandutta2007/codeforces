import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayDeque;
import java.util.Deque;

public class PrC {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		go(br, System.out);
		br.close();
		System.exit(0);
	}

	public static void go(BufferedReader br, PrintStream out) throws Exception {
		char[] s = br.readLine().toCharArray();
		Deque<VString> stack = new ArrayDeque<VString>();
		int max = 0;
		VString best = null;
		for(int i = 0; i < s.length; i++) {
			char c = s[i];
			if(c == '[') {
				stack.push(new VString(i, i + 1, -1));
			} else if (c == '(') {
				stack.push(new VString(i, i + 1, -2));
			} else {
				if(stack.isEmpty()) continue;
				VString prev = stack.pop();
				if(prev.v < 0) {
					if(prev.v == ((c == ']') ? -1 : -2)){
						prev.e ++;
						prev.v = (c == ']') ? 1 : 0;
					} else {
						stack.clear();
						continue;
					}
				} else {
					if(!stack.isEmpty() && stack.pop().v == ((c == ']') ? -1 : -2)) {
						prev.s --;
						prev.e ++;
						if(c == ']') prev.v ++;
					} else {
						stack.clear();
						continue;
					}
				}
				if(!stack.isEmpty() && stack.peek().v >= 0) {
					stack.peek().e = prev.e;
					stack.peek().v += prev.v;
					prev = stack.peek();
				} else {
					stack.push(prev);
				}
				if(prev.v > max) {
					max = prev.v;
					best = prev;
				}
			}
		}
		out.println(max);
		if(best != null)
			for(int i = best.s; i < best.e; i++) 
				out.print(s[i]);
		out.println();
	}

	static class VString {
		public int v, s, e;

		public VString(int start, int end, int value) {
			this.s = start;
			this.e = end;
			this.v = value;
		}
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}