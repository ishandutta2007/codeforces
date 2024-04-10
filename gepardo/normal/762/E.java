import java.io.*;
import java.util.*;

public class task6 {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		TaskSolver solver = new TaskSolver(reader, writer);
		solver.solve();
		reader.close();
		writer.close();
	}
}

class RadioStation {
	public int x;
	public int r;
	public int f;
	
	public RadioStation(int aX, int aR, int aF) {
		x = aX;
		r = aR;
		f = aF;
	}
	
	public RadioStation(String s) {
		StringTokenizer tokenizer = new StringTokenizer(s);
		x = Integer.parseInt(tokenizer.nextToken());
		r = Integer.parseInt(tokenizer.nextToken());
		f = Integer.parseInt(tokenizer.nextToken());
	}
	
	public final String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append(x).append(" ").append(r).append(" ").append(f);
		return builder.toString();
	}
}

class Event implements Comparable<Event> {
	public static enum EventType {
		OPEN, 
		CLOSE;
		
		public int toInteger() {
			return (this == OPEN) ? 0 : 1;
		}
	}
	
	public int t;
	public EventType type;
	public RadioStation station;
	
	public Event(EventType aType, RadioStation aStation) {
		type = aType;
		station = aStation;
		if (aType == EventType.OPEN) {
			t = aStation.x;
		} else {
			t = aStation.x + aStation.r;
		}
	}
	
	@Override
	public int compareTo(Event o) {
		if (this.t < o.t) {
			return -1;
		}
		if (this.t > o.t) {
			return 1;
		}
		if (this.type.toInteger() < o.type.toInteger()) {
			return -1;
		}
		if (this.type.toInteger() > o.type.toInteger()) {
			return 1;
		}
		return 0;
	}
}

class FenwickTree {
	private int n;
	private int v[];
	
	public final void modify(int i, int delta) {
		while (i < n) {
			v[i] += delta;
			i |= i + 1;
		}
	}
	
	public final int sum(int i) {
		int res = 0;
		while (i >= 0) {
			res += v[i];
			i &= i + 1;
			i--;
		}
		return res;
	}
	
	public final int sum(int l, int r) {
		if (l > r) {
			return 0;
		} else {
			return sum(r) - sum(l-1);
		}
	}
	
	public FenwickTree(int pN) {
		n = pN;
		v = new int[n];
	}
}

class TaskSolver {
	private static class IntegerList extends ArrayList<Integer> {
		public final int lowerBound(int key) {
			// first one >= key
			if (isEmpty()) {
				return 0;
			}
			if (get(size() - 1) < key) {
				return size();
			}
			int l = 0, r = size() - 1;
			while (l < r) {
				int m = (l + r) / 2;
				if (get(m) >= key) {
					r = m;
				} else {
					l = m+1;
				}
			}
			return l;
		}
		
		public final int upperBound(int key) {
			// last one <= key
			if (isEmpty()) {
				return -1;
			}
			if (get(0) > key) {
				return -1;
			}
			int l = 0, r = size() - 1;
			while (l < r) {
				int m = (l + r + 1) / 2;
				if (get(m) <= key) {
					l = m;
				} else {
					r = m-1;
				}
			}
			return l;
		}
	}
	
	private BufferedReader reader;
	private BufferedWriter writer;	
	private FenwickTree[] fenwicks;
	private IntegerList[] coords;
	private int n, k;
	private RadioStation[] stations;
	
	public TaskSolver(BufferedReader aReader, BufferedWriter aWriter) {
		reader = aReader;
		writer = aWriter;	
		fenwicks = new FenwickTree[10001];
		coords = new IntegerList[10001];
	}
	
	private final void add(int x, int f, int delta) throws Exception {
		int i = Collections.binarySearch(coords[f], x);
		fenwicks[f].modify(i, delta);
	}
	
	private final long count(int l, int r, int f) throws Exception {
		if (f < 0 || f >= coords.length) {
			return 0;
		}
		l = coords[f].lowerBound(l);
		r = coords[f].upperBound(r);
		return fenwicks[f].sum(l, r);
	}
	
	private static IntegerList sortAndCompress(IntegerList v) {
		if (v.isEmpty()) {
			return v;
		}
		Collections.sort(v);
		IntegerList q = (IntegerList)v.clone();
		v.clear();
		v.add(q.get(0));
		for (int i = 1; i < q.size(); i++) {
			if (q.get(i) != q.get(i-1)) {
				v.add(q.get(i));
			}
		}
		return v;
	}
	
	public void solve() throws Exception {
		StringTokenizer token = new StringTokenizer(reader.readLine());
		n = Integer.parseInt(token.nextToken());
		k = Integer.parseInt(token.nextToken());
		stations = new RadioStation[n];
		ArrayList<Event> events = new ArrayList<Event>();
		for (int i = 0; i < coords.length; i++) {
			coords[i] = new IntegerList();
		}
		for (int i = 0; i < n; i++) {
			stations[i] = new RadioStation(reader.readLine());
			coords[stations[i].f].add(stations[i].x);
			events.add(new Event(Event.EventType.OPEN, stations[i]));
			events.add(new Event(Event.EventType.CLOSE, stations[i]));
		}	
		Collections.sort(events);
		long res = 0;
		for (int i = 0; i < coords.length; i++) {
			coords[i] = sortAndCompress(coords[i]);
			fenwicks[i] = new FenwickTree(coords[i].size());
		}
		for (int i = 0; i < events.size(); i++) {
			Event curEvent = events.get(i);
			RadioStation cur = curEvent.station;
			if (curEvent.type == Event.EventType.OPEN) {
				for (int j = cur.f - k; j <= cur.f + k; j++) {
					res += count(cur.x - cur.r, cur.x, j);
				}
				add(cur.x, cur.f, +1);
			} else {
				add(cur.x, cur.f, -1);
			}
		}
		writer.write(Long.toString(res));
	}
}